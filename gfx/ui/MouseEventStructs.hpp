#ifndef MOUSEEVENTSTRUCTS_HPP
#define MOUSEEVENTSTRUCTS_HPP

typedef struct {
    int x;
    int y;
    char dX;
    char dY;
    bool left,middle,right;
} MouseOnMoveEvent;

typedef struct {
    int x;
    int y;
    char dX;
    char dY;
    bool left,middle,right;
} MouseOnDownEvent;

typedef struct {
    int x;
    int y;
    char dX;
    char dY;
    bool left,middle,right;
} MouseOnReleaseEvent;

#endif