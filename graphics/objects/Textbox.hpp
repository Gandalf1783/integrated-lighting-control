#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "UiObject.hpp"
#include "Texture.hpp"

class Textbox : public UiObject {
    public:
        Textbox(SDL_Renderer* renderer);
        Textbox(SDL_Renderer* renderer, bool renderEverywhere);
        ~Textbox();
        void render(Display* d);
    private:
        SDL_Renderer* renderer;
        Texture* textbox;
        bool renderEverywhere;

};

#endif