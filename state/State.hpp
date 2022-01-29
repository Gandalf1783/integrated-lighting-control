#include <iostream>
#include <string>

#ifndef STATE_HPP
#define STATE_HPP

class State {
    private:
        std::string name;
    public:
        virtual void render(char* framebuffer);
};

#endif