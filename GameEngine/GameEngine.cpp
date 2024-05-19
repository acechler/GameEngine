#include "Sprite.h"
#include <conio.h> // for _kbhit() and _getch()
#include <windows.h>


// Function to hide the cursor
void hideCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // set the cursor visibility to false
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

// Function to show the cursor
void showCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = TRUE; // set the cursor visibility to true
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

int main() {

    hideCursor();

    // Create a 2x2 sprite
    Sprite sprite(2, 2);
    sprite.setPixel(0, 0, '#');
    sprite.setPixel(1, 0, '#');
    sprite.setPixel(0, 1, '#');
    sprite.setPixel(1, 1, '#');

    int x = 0, y = 0;
    sprite.moveTo(x, y);

    bool running = true;
    while (running) {
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
            case 'w': // move up
                y = (y > 0) ? y - 1 : y;
                break;
            case 's': // move down
                y = (y < 24) ? y + 1 : y; // assuming console height is 25
                break;
            case 'a': // move left
                x = (x > 0) ? x - 1 : x;
                break;
            case 'd': // move right
                x = (x < 78) ? x + 1 : x; // assuming console width is 80
                break;
            case 'q': // quit
                running = false;
                break;
            default:
                break;
            }
            sprite.moveTo(x, y);
        }
        Sleep(50); // delay to reduce CPU usage
    }
    showCursor();
    return 0;
}
