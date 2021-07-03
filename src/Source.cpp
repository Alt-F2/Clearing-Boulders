#define _ WIN32_WINNT 0x0500
#include "Game.h"
#include <windows.h>
#include <iostream>

int main()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);

    Game game;
    game.run();
    return 0;
}