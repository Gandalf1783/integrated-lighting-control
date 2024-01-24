
#include <chrono>
#include <cmath>

#include "Effect.hpp"

#ifndef SineWave_HPP
#define SineWave_HPP

class SineWave : Effect {

    private:
        
    public:
        double calcValue(std::chrono::milliseconds startMs, std::chrono::milliseconds deltaTime);
};


#endif