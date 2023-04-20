#include "Textbox.hpp"

Textbox::Textbox(SDL_Renderer* renderer) {
    this->renderer = renderer;
    this->renderEverywhere = true;
    this->textbox = new Texture(renderer);
    this->textbox->loadTexture("/root/dmx_engine/assets/text_input_green.png");
    this->textbox->setPosType(CENTER);
    this->textbox->setSize(200,32);
};

Textbox::Textbox(SDL_Renderer* renderer, bool renderEverywhere) {
    this->renderer = renderer;
    this->renderEverywhere = renderEverywhere;
    this->textbox = new Texture(renderer);
    this->textbox->loadTexture("/root/dmx_engine/assets/text_input_green.png");
};

Textbox::~Textbox() {
    delete this->textbox;
    this->textbox = nullptr;
};

void Textbox::render(Display* d) {
    this->textbox->render(d);
};