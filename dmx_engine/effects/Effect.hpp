#include <chrono>

#include "../../fixture/channel/Channel.hpp"
#include "../../fixture/Selectable.hpp"

#ifndef EFFECT_HPP
#define EFFECT_HPP

#define EFFECT_MODE_ABSOLUTE A
#define EFFECT_MODE_RELATIVE R

class Effect {
    protected:
        double min;
        double max;
        double hertz;
        double width; // In seconds
        double attack;
        double decay;
        char mode; // Bit 0: Absolute (1)/Relative (0); Bit 1: Selective (1)/Template (0); Bit 2-3: Direction (FWD = 00, BCKW = 01, BOUNFWD = 10, BOUNBCKW=11); Bit 4: Single Shot
    public:
        Effect(double min, double max);
        void tick();
        virtual double calcValue(std::chrono::milliseconds startMs, std::chrono::milliseconds currentMs) = 0;
        bool isSingleShot();
        bool isAbsolute();
        bool isRelative();
        bool isSelective();
        bool isTemplate();
        void setSingleShot(bool value);
        void setAbsolute(bool value);
        void setSelective(bool value);
};


#endif