#include "Display.hpp"

Display::Display(unsigned int displayNum) {
    displayDimensions = new SDL_Rect();
    window = nullptr;
    renderer = nullptr;

    this->displayNum = displayNum;
    this->shouldThreadStop = false;
    
    this->fps = 0;
    this->frameTime = 0;
    this->frameCount = 0;
    this->showDebug = true;

    printf("[DISPLAY] (%d) : Querying Bounds... \n", displayNum);
    SDL_GetDisplayBounds(displayNum, displayDimensions); // SDL_GetDisplayBounds expects an existing SDL_Rect as a 2nd argument.
    printf("[DISPLAY] (%d) : Creating Window with dimensions %dx&%d beginning at %dx%d.\n", displayNum, displayDimensions->w, displayDimensions->h, displayDimensions->x, displayDimensions->y);

    window = SDL_CreateWindow("ILC", displayDimensions->x, displayDimensions->y, displayDimensions->w, displayDimensions->h, SDL_WINDOW_BORDERLESS);
    
    if(window == nullptr ) {
        printf("[DISPLAY] (%d) : Failed to create Display: SDL_Window (= 0x%x) is NULL.\n", displayNum, window);
        return;
    }

    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == nullptr) {
        printf("[DISPLAY] (%d) : Failed to create Display: SDL_Renderer (= 0x%x) is NULL.\n", displayNum, renderer);
        return;
    }

    printf("[DISPLAY] (%d) : Window and Rendercontext created with size %dx%d\n", displayNum, displayDimensions->w, displayDimensions->h);
};

Display::~Display() {

    for(int i = 0; i < this->uiObjects.size(); i++) {
        delete this->uiObjects.at(i);
    }

    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    
    this->renderer = nullptr;
    this->window = nullptr;

    delete this->displayDimensions;
    this->displayDimensions = nullptr;
};

void Display::start() {
    printf("[DISPLAY] (%d) : Starting Render Thread...\n", displayNum);
    this->renderThread = std::thread(&Display::renderLoop, this);
};

void Display::stop() {
    printf("[DISPLAY] (%d) : Exiting Render Thread...\n", displayNum);
    this->shouldThreadStop = true;
    this->renderThread.join();
    printf("[DISPLAY] (%d) : Exited.\n", displayNum);
};

void Display::renderLoop() {
    TTF_Init();
    
    TTF_Font* font = TTF_OpenFont("/root/dmx_engine/arial.ttf", 20);
    if(font == nullptr) {
        printf("Font not laoded.");
        exit(18);
    }
    printf("Font loaded: 0x%x\n", font);

    DebugView *db = new DebugView(this->renderer, font, &frameTime, &fps, &frameCount);
    Texture *tx = new Texture(this->renderer);
    Grid *gd = new Grid(this->renderer);
    Textbox* tb = new Textbox(this->renderer);

    tx->loadTexture("/root/dmx_engine/assets/border_tile_cyan_00ffd2.bmp");

    this->uiObjects.push_back(tx);
    this->uiObjects.push_back(gd);
    this->uiObjects.push_back(tb);
    //this->uiObjects.push_back(db);

    int targetFps = currentConfig.get<int>("graphics.targetFps");
    double timeConstantDelay = 1/targetFps*1000;

    while(!this->shouldThreadStop) {
        SDL_RenderClear(renderer);

        for(int i = 0; i < this->uiObjects.size(); i++) {
            this->uiObjects.at(i)->render(this);
        }


        if(this->showDebug) {
            db->render(this);
        }

        SDL_RenderPresent(renderer);
        
        SDL_Delay(timeConstantDelay);
        
        this->frameCount++;
        if(this->frameCount >= targetFps)
            this->frameCount = 0;
    }

    TTF_CloseFont(font);
    TTF_Quit();
};

SDL_Rect* Display::getDisplayDimensions() {
    return this->displayDimensions;
}