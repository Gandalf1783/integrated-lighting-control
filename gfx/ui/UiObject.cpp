#include "UiObject.hpp"

UiObject::UiObject() {
  std::cout << "UIObject was created!" << '\n';
};

uiObjectInfo UiObject::getUiObjectInfo() {
  return this->objectInfo;
}