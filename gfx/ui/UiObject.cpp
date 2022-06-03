#include "UiObject.hpp"

/*
  # This is the parent UI-Object which is being inherited by all other ui/ classes. 
  # It contains an ObjectInfo, but I think i can remove that.
*/

UiObject::UiObject() {
};

uiObjectInfo UiObject::getUiObjectInfo() {
  return this->objectInfo;
}