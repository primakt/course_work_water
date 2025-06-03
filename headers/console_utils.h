#pragma once
#include <windows.h>
#include <iostream>

enum Color {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE
};

void setColor(Color text, Color bg = BLACK);
void gotoxy(int x, int y);
void clearScreen();