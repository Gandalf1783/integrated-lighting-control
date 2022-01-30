clear
echo "Compiling..."
echo "Main" &&
g++ -c main.cpp &&
echo "Display" &&
g++ -c gfx/Display.cpp &&
echo "UiManager" &&
g++ -c gfx/UiManager.cpp &&
echo "UiObject" &&
g++ -c gfx/ui/UiObject.cpp &&
echo "Image" &&
g++ -c gfx/ui/Image.cpp &&
echo "ProgressBar" &&
g++ -c gfx/ui/ProgressBar.cpp &&
echo "Font" &&
g++ -c gfx/bitmapfont/Font.cpp &&
echo "Text" &&
g++ -c gfx/ui/Text.cpp &&
echo "Rectangle"
g++ -c gfx/ui/Rectangle.cpp &&
clear &&
echo "Linking..." &&
g++ -g3 main.o Rectangle.o Font.o Text.o ProgressBar.o Display.o UiManager.o UiObject.o Image.o -pthread && clear && echo "Running..." && ./a.out
