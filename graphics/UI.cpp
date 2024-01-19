#include "UI.hpp"

using namespace std::chrono_literals;

UI::UI() {
    this->shouldThreadStop = false;
};

UI::~UI() {
    // SDL_FreeCursor(this->cursor);
};

void UI::init() {
    printf("[UI] Initialising Displays and Graphics\n");
    int sdlInitRes = SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_TIMER);
    
    printf("sdlInitRes: %d\n", sdlInitRes);

    this->numDisplays = SDL_GetNumVideoDisplays();
    
    for(int i = 0; i < this->numDisplays; i++) {
        Display* display;
        display = new Display(i);
        
        if(display == nullptr)
            continue;
        
        this->displays.push_back(display);
    }
    
    //printf("Displays created Font\n");

    printf("[UI] : Init done.\n");
};

void UI::start() {
    printf("[UI] : Starting Event Thread\n");
    eventThread = std::thread(&UI::sdlEventLoop, this);
    printf("[UI] : Starting Display Render Threads\n");
    for(int i = 0; i < this->displays.size(); i++) {
        this->displays.at(i)->start();
    }
};

void UI::sdlEventLoop() {
    FrameLimit<30> fr;
    int i = 0;

    flashStateFast = false;
    flashStateSlow = false;

    while(!this->shouldThreadStop) {
        
        SDL_Event e;

        // Flash Booleans
        if((i % 8) == 0) {
            flashStateFast = !flashStateFast;
        }

        if((i % 16) == 0) {
            flashStateSlow = !flashStateSlow;
        }
        
        i++;
    

        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                case SDL_KEYDOWN:
                    currentState = STOP_REQUEST;
                    break;
                case SDL_MOUSEMOTION:
                    SDL_GetMouseState( &x, &y );
                    // focusedWindow = SDL_GetMouseFocus();
                    break;
                case SDL_MOUSEWHEEL:
                    if(e.wheel.y > 0) // scroll up
                    {
                        defaultWaittime += 0.5f;
                    }
                    else if(e.wheel.y < 0) // scroll down
                    {
                        defaultWaittime -= 0.5f;
                    }
                    break;
                default:
                    break;
            }
        }
        fr.sleep(); // Sleep to achieve 30 Fps
    }
}

void UI::displayStopDialog() {
    currentState = STOPPING;
    printf("[UI] : Dialog returned: STOP\n");
}

void UI::stop() {
    printf("[UI] : UI EVENT LOOP EXIT!\n");
    this->shouldThreadStop = true;
    this->eventThread.join();

    for(int i = 0; i < this->displays.size(); i++) {
        printf("[UI] : Waiting for Display %d's renderthread to exit...\n", i);
        this->displays.at(i)->stop();
    }
    printf("[UI] : Renderthreads stopped.\n");
};

void UI::freeMemory() {
    printf("Was SDL initialized: %d\n", SDL_WasInit(0));

    for(int i = 0; i < this->displays.size(); i++) {
        delete this->displays.at(i);
    }

    this->displays.clear();
    
    TTF_Quit();
    SDL_Quit();
};

bool UI::isUIRunning() {
    return !this->shouldThreadStop;
};
