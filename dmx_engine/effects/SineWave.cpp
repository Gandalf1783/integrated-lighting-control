#include "SineWave.hpp"


double SineWave::calcValue(std::chrono::milliseconds startMs, std::chrono::milliseconds currentMs) {
    return std::sin((float) ((2*M_PI)/ this->width * ((currentMs.count()-startMs.count()))));

};