#include "UiObject.hpp"

UiObject::UiObject() {
    this->posType = ABS;
};

//Methods that can be overwritten
void UiObject::setPos(int x, int y) {
    this->drawingRect.x = x;
    this->drawingRect.y = y;
}
void UiObject::setSize(int width, int height) {
    this->drawingRect.w = width;
    this->drawingRect.h = height;
}
void UiObject::setPosType(PositionType type) {
    this->posType = type;
}
void UiObject::setRenderTarget(RenderTarget target) {
    this->renderTarget = target;
}