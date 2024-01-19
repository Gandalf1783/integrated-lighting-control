#ifndef DEBUG_VIEW_HPP
#define DEBUG_VIEW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "UiObject.hpp"

class Text;

class DebugView : public UiObject {

    public:
        DebugView(SDL_Renderer* renderer, TTF_Font *font, float *frameTime, float *fps, unsigned int* frameCount);
        ~DebugView();
        void render(Display* d);
    private:
        SDL_Renderer* renderer;
        TTF_Font* font;
        char* bufFPS;
        char* buf;
    
        Text* dbgText;
        Text* txtFPS;

        float* frameTime;
        float* fps;
        unsigned int* frameCount;

};

#include "Text.hpp"

#endif