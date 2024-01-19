#include "DebugView.hpp"

DebugView::DebugView(SDL_Renderer* renderer, TTF_Font *font, float* renderTime, float* fps, unsigned int* frameCount) {
    this->renderer = renderer;
    this->font = font;
    this->frameTime = renderTime;
    this->fps = fps;
    this->frameCount = frameCount;

    this->bufFPS = (char*) malloc(256);

    this->dbgText = new Text(renderer, font);
    this->txtFPS = new Text(renderer, font);

    this->dbgText->setText("[DEBUG]");
    this->txtFPS->setText(bufFPS);

    this->dbgText->setPos(0,0);
    this->txtFPS->setPos(0,20);
};

DebugView::~DebugView() {
    if(this->bufFPS != nullptr) {
        free(this->bufFPS);
        delete this->txtFPS;
        this->txtFPS = nullptr;
    }

    if(this->buf != nullptr) {
        free(this->buf);
        delete this->buf;
        this->buf = nullptr;
    }

    delete this->dbgText;
    delete this->txtFPS;
};

void DebugView::render(Display* d) {
    sprintf(bufFPS, "(%d) (FF: %d | FS: %d)TIME: %3.1lfms / FPS: %5.1lf", *frameCount, flashStateFast, flashStateSlow, *frameTime, *fps);
    this->txtFPS->setText(bufFPS);
    this->dbgText->render(d);
    this->txtFPS->render(d);
};