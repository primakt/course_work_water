#pragma once
#include <windows.h>
#include <iostream>

enum Color {
    BLACK, DARK_BLUE, DARK_GREEN, DARK_CYAN, DARK_RED, DARK_MAGENTA, DARK_YELLOW, GRAY,
    DARK_GRAY, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE
};

const int WIDTH = 80;
const int HEIGHT = 25;
const int SKY_HEIGHT = 6;
const int RIVER_HEIGHT = 6;
const int FOREST_HEIGHT = HEIGHT - SKY_HEIGHT - RIVER_HEIGHT;

void setColor(Color text, Color bg = BLACK);
void gotoxy(int x, int y);
void clearScreen();