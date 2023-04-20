#ifndef UIOBJECT_HPP
#define UIOBJECT_HPP

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

inline bool flashStateSlow;
inline bool flashStateFast;

enum FlashState {NONE, FAST, SLOW};
enum PositionType {ABS, CENTER};
enum RenderTarget {DEFAULT, ALL};

class Display; // Forward Decl.

class UiObject {

    public:
        UiObject();
        UiObject(SDL_Renderer* renderer);
        virtual ~UiObject() = default;
        virtual void render(Display* d) = 0;
        virtual void setPos(int x, int y);
        virtual void setSize(int width, int height);
        void setPosType(PositionType type);
        void setRenderTarget(RenderTarget target);
    protected:
        SDL_Rect drawingRect;
        PositionType posType;
        RenderTarget renderTarget;

};

#include "../Display.hpp"
#endif