clear
echo "Compiling..."
echo "Main" &&
g++ -c main.cpp -o build/main.o &&
echo "Display" &&
g++ -c gfx/Display.cpp -o build/Display.o &&
echo "UiManager" &&
g++ -c gfx/UiManager.cpp -o build/UiManager.o &&
echo "UiObject" &&
g++ -c gfx/ui/UiObject.cpp -o build/UiObject.o &&
echo "Image" &&
g++ -c gfx/ui/Image.cpp -o build/Image.o &&
echo "ProgressBar" &&
g++ -c gfx/ui/ProgressBar.cpp -o build/ProgressBar.o &&
echo "Font" &&
g++ -c gfx/bitmapfont/Font.cpp -o build/Font.o &&
echo "Text" &&
g++ -c gfx/ui/Text.cpp -o build/Text.o &&
echo "Rectangle"
g++ -c gfx/ui/Rectangle.cpp -o build/Rectangle.o &&
echo "Window" &&
g++ -c gfx/ui/Window.cpp -o build/Window.o &&
echo "Line" &&
g++ -c gfx/ui/Line.cpp -o build/Line.o &&
echo "InputManager" &&
g++ -c input/InputManager.cpp -o build/InputManager.o &&
echo "Mouse" &&
g++ -c gfx/ui/Mouse.cpp -o build/Mouse.o &&
echo "Linking..." &&
g++ -g3 build/*.o -pthread && echo "Running..." && ./a.out
