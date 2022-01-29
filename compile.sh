g++ -c gfx/Display.cpp -o gfx/Display.o
g++ -c main.cpp -o main.o
g++ gfx/Display.o main.o -o a.out
./a.out
