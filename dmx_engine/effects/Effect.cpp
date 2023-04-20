#include "Effect.hpp"

bool Effect::isSingleShot() {
    return (mode & (1<<4));
};

bool Effect::isAbsolute() {
    return (mode & (1<<0));
};

bool Effect::isRelative(){
    return !(mode & (1<<0));
};

bool Effect::isSelective() {
    return (mode & (1<<1));
};

bool Effect::isTemplate() {
    return !(mode & (1<<1));
};

void Effect::setSingleShot(bool value) {
    this->mode = (this->mode & ~(1<<4)) | (value<<4);
};

void Effect::setAbsolute(bool value) {
    this->mode = (this->mode & ~(1<<0)) | (value<<0);
};

void Effect::setSelective(bool value) {
    this->mode = (this->mode & ~(1<<1)) | (value<<1);
};