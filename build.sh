clear
echo "Compiling..."
mkdir -p build/
echo "Main" &&
g++ -g -c main.cpp -o build/main.o &&
echo "Display" &&
g++ -g -c gfx/Display.cpp -o build/Display.o &&
echo "UiManager" &&
g++ -g -c gfx/UiManager.cpp -o build/UiManager.o &&
echo "UiObject" &&
g++ -g -g -c gfx/ui/UiObject.cpp -o build/UiObject.o &&
echo "Image" &&
g++ -g -c gfx/ui/Image.cpp -o build/Image.o &&
echo "ProgressBar" &&
g++ -g -c gfx/ui/ProgressBar.cpp -o build/ProgressBar.o &&
echo "Font" &&
g++ -g -c gfx/bitmapfont/Font.cpp -o build/Font.o &&
echo "Text" &&
g++ -g -c gfx/ui/Text.cpp -o build/Text.o &&
echo "Rectangle" &&
g++ -g -c gfx/ui/Rectangle.cpp -o build/Rectangle.o &&
echo "Window" &&
g++ -g -c gfx/ui/Window.cpp -o build/Window.o &&
echo "Line" &&
g++ -g -c gfx/ui/Line.cpp -o build/Line.o &&
echo "InputManager" &&
g++ -g -c input/InputManager.cpp -o build/InputManager.o &&
echo "Mouse" &&
g++ -g -c gfx/ui/Mouse.cpp -o build/Mouse.o &&
echo "Button" &&
g++ -g -c gfx/ui/Button.cpp -o build/Button.o
echo "ContextMenu" &&
g++ -g -c gfx/ui/ContextMenu.cpp -o build/ContextMenu.o &&
echo "Serial" &&
g++ -g -c serial/Serial.cpp -o build/Serial.o &&
echo "Log" &&
g++ -g -c log/Log.cpp -o build/Log.o &&
echo "LogEvent" && 
g++ -g -c log/LogEvent.cpp -o build/LogEvent.o &&
echo "Framebuffer" &&
g++ -g -c gfx/Framebuffer.cpp -o build/Framebuffer.o &&
echo "Linking..." &&
#g++ -g3 build/*o -pthread && echo "Running" && ./a.out
g++ -fsanitize=undefined,address -g3 build/*.o -pthread
#g++ -g -pthread build/*.o
