#include "DMXEngine.hpp"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"

#define ANSI_COLOR_RESET   "\x1b[0m"

//Utility Function
int min(int i, int j) {
    return (i < j ? i : j);
};

using namespace std;
using namespace std::chrono;

DMXEngine::DMXEngine() {
    for(int i = 0; i < DEFAULT_DMX_UNIVERSES; i++) {
        Universe* u = new Universe(i);
        this->universes.push_back(u);
    }
    printf("[DMXEngine] Initiated %d universes.\n", DEFAULT_DMX_UNIVERSES);
    this->universeNum = DEFAULT_DMX_UNIVERSES;
    this->sequenceNum = 0;
}

DMXEngine::DMXEngine(unsigned short universes) {
    universes = min(universes, MAX_DMX_UNIVERSES);
    for(int i = 0; i < universes; i++) {
        Universe* u = new Universe(i);
        this->universes.push_back(u);
    }
    printf("[DMXEngine] Initiated %d universes.\n", universes);
    this->universeNum = universes;
    this->sequenceNum = 0;
};

/*
    This is the Output-Thread
*/
void DMXEngine::runOutput() {
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_YELLOW "DMXENGINE" ANSI_COLOR_RESET "] : Thread is " ANSI_COLOR_GREEN "running" ANSI_COLOR_RESET ".\n");
    this->shouldThreadStop = false;
    
    FrameLimit<42> frameLimiter;
    while(!this->shouldThreadStop) {
        //printf("[DMXENGINE] Shall not stop.\n");
        
        //TODO: Apply the effects here!
        runInputs();
        runEffects();

        for(int i = 0; i < this->universeNum; i++) {
            Universe* currentUniverse;
            currentUniverse = this->universes.at(i);
            
            unsigned char* dmxValues = (currentUniverse->getDMXValues());
            
            for(int i = 0; i < this->dmxOutputs.size(); i++) {
                Output *output = dmxOutputs.at(i);
                output->sendUniverse(currentUniverse, sequenceNum);
            }
        }
    
        sequenceNum++;
        frameLimiter.sleep(); // Should limit to 42 dmx frames per sec
    }
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_YELLOW "DMXENGINE" ANSI_COLOR_RESET "] : Output-Thread has stopped.\n");
};

/*
    This is the Effect-Thread
*/
void DMXEngine::runEffects() {
    // double delta;

    // milliseconds ms = duration_cast< milliseconds >(
    //     system_clock::now().time_since_epoch()
    // );
    // FrameLimit<30> frameLimiter;
    // while(!this->shouldThreadStop) {
        for(int i = 0; i < this->universeNum; i++ ) {
            for(int j = 0; j < 512; j++) {

                this->universes.at(i)->setDmxValue(j,j+this->sequenceNum);      
                
            }
        }


    //     frameLimiter.sleep(); // Should limit to 30 dmx frames per sec
    // }
    
    // printf(ANSI_COLOR_RESET "[" ANSI_COLOR_YELLOW "DMXENGINE" ANSI_COLOR_RESET "] : Effects-Thread has stopped.\n");
}
    
void DMXEngine::runInputs() {
    // FrameLimit<30> frameLimiter;
    // while(!this->shouldThreadStop) {

    //     frameLimiter.sleep();
    // }
    
    // printf(ANSI_COLOR_RESET "[" ANSI_COLOR_YELLOW "DMXENGINE" ANSI_COLOR_RESET "] : Input-Thread has stopped.\n");
}

void DMXEngine::addOutput(Output* output) {
    this->dmxOutputs.push_back(output);
};


void DMXEngine::start() {
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_YELLOW "DMXENGINE" ANSI_COLOR_RESET "] : Starting Thread \n");
    this->dmxEngineOutputThread = std::thread(&DMXEngine::runOutput, this);
  //  this->dmxEngineEffectThread = std::thread(&DMXEngine::runEffects, this);
  //  this->dmxEngineInputThread = std::thread(&DMXEngine::runInputs, this);
}

void DMXEngine::stop() {
     printf(ANSI_COLOR_RESET "[" ANSI_COLOR_YELLOW "DMXENGINE" ANSI_COLOR_RESET "] : " ANSI_COLOR_RED "Stopping" ANSI_COLOR_RESET " Thread \n");
    this->shouldThreadStop = true;
    this->dmxEngineOutputThread.join();
   // this->dmxEngineEffectThread.join();
   // this->dmxEngineInputThread.join();
}

void DMXEngine::freeMemory() {
    for(Output* out : this->dmxOutputs) {
        out->stop();
        out->freeMemory();
        delete out;
    }

    for(Universe* uni : this->universes) {
        uni->freeMemory();
        delete uni;
    }

    // for(Effect* effect : this->effect) {
    //    effect->freeMemory();
    // }

    this->dmxOutputs.clear();
    this->universes.clear();
    //this->effect.clear();
}