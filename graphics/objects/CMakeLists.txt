set(effectsSrc UiObject.cpp Text.cpp DebugView.cpp Texture.cpp Grid.cpp GridElement.cpp Textbox.cpp)

message("-- Adding target DEMO")

add_library(uiObjects STATIC ${effectsSrc})
