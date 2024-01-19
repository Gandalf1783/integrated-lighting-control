#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <thread>
#include <memory>

#include "FrameLimit.hpp"

#include "Universe.hpp"
#include "effects/Effect.hpp"
#include "../dmx_output/Output.hpp"
#include "../dmx_output/ArtNet.hpp"

#ifndef DMXENGINE_HPP
#define DMXENGINE_HPP

#define DEFAULT_DMX_UNIVERSES 16
#define MAX_DMX_UNIVERSES 20

class DMXEngine {
    private:
        int universeNum;
        unsigned char sequenceNum;
        std::vector<std::shared_ptr<Universe>> universes;
        std::vector<std::shared_ptr<Output>> dmxOutputs;
        std::vector<std::shared_ptr<Effect>> runningEffects;


        std::thread dmxEngineInputThread;
        std::thread dmxEngineOutputThread;
        std::thread dmxEngineEffectThread;

        bool shouldThreadStop;
        void runOutput();
        void runEffects();
        void runInputs();
    
    public:
        DMXEngine();
        DMXEngine(unsigned short universes);
        void addOutput(std::shared_ptr<Output> output);
        void setChannel(unsigned short universes, unsigned char value);
        void start();
        void stop();
        void freeMemory();
};

#endif