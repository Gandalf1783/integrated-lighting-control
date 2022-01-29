#include <iostream>
#include <string>
#include "State.hpp"

#include "../gfx/ui/Image.hpp"
#include "../gfx/ui/Text.hpp"


#ifndef STARTSTATE_HPP
#define STARTSTATE_HPP

class StartState : public State {
    private:
        std::string name;
        
        Image background;
        Text t;
    public:
        StartState();
        void render(char* framebuffer);
};

#endif