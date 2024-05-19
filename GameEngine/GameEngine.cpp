#include "Sprite.h"
#include "Actor.h"
#include <conio.h> // for _kbhit() and _getch()
#include <windows.h>
#include <vector>
#include <cmath> // for abs()

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

// Function to draw all actors
void drawActors(const std::vector<Actor>& actors) {
    for (const auto& actor : actors) {
        actor.getSprite().draw();
    }
}

// Function to clear all actors
void clearActors(const std::vector<Actor>& actors) {
    for (const auto& actor : actors) {
        actor.getSprite().clear();
    }
}

// Function to move the chaser actor towards the player actor
void moveChaser(Actor& chaser, int playerX, int playerY) {
    COORD chaserPos = chaser.getSprite().getPosition();
    int chaserX = chaserPos.X;
    int chaserY = chaserPos.Y;

    if (chaserX < playerX) {
        chaserX++;
    }
    else if (chaserX > playerX) {
        chaserX--;
    }

    if (chaserY < playerY) {
        chaserY++;
    }
    else if (chaserY > playerY) {
        chaserY--;
    }

    chaser.getSprite().moveTo(chaserX, chaserY);
}

int main() {
    hideCursor();

    // Create sprites
    Sprite sprite1(2, 2);
    sprite1.setPixel(0, 0, '#');
    sprite1.setPixel(1, 0, '#');
    sprite1.setPixel(0, 1, '#');
    sprite1.setPixel(1, 1, '#');

    Sprite sprite2(3, 3);
    sprite2.setPixel(0, 0, '*');
    sprite2.setPixel(1, 0, '*');
    sprite2.setPixel(2, 0, '*');
    sprite2.setPixel(0, 1, '*');
    sprite2.setPixel(1, 1, '*');
    sprite2.setPixel(2, 1, '*');
    sprite2.setPixel(0, 2, '*');
    sprite2.setPixel(1, 2, '*');
    sprite2.setPixel(2, 2, '*');

    Sprite spriteChaser(2, 2);
    spriteChaser.setPixel(0, 0, 'C');
    spriteChaser.setPixel(1, 0, 'C');
    spriteChaser.setPixel(0, 1, 'C');
    spriteChaser.setPixel(1, 1, 'C');

    // Create actors
    Actor player1("Player1", sprite1);
    Actor player2("Player2", sprite2);
    Actor chaser("Chaser", spriteChaser);

    std::vector<Actor> actors = { player1, player2, chaser };

    // Initial positions
    int x1 = 0, y1 = 0;
    int x2 = 10, y2 = 10;
    int xChaser = 20, yChaser = 20;

    player1.getSprite().moveTo(x1, y1);
    player2.getSprite().moveTo(x2, y2);
    chaser.getSprite().moveTo(xChaser, yChaser);

    bool running = true;
    while (running) {
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
            case 'w': // move player1 up
                y1 = (y1 > 0) ? y1 - 1 : y1;
                break;
            case 's': // move player1 down
                y1 = (y1 < 24) ? y1 + 1 : y1; // assuming console height is 25
                break;
            case 'a': // move player1 left
                x1 = (x1 > 0) ? x1 - 1 : x1;
                break;
            case 'd': // move player1 right
                x1 = (x1 < 78) ? x1 + 1 : x1; // assuming console width is 80
                break;
            case 'i': // move player2 up
                y2 = (y2 > 0) ? y2 - 1 : y2;
                break;
            case 'k': // move player2 down
                y2 = (y2 < 24) ? y2 + 1 : y2; // assuming console height is 25
                break;
            case 'j': // move player2 left
                x2 = (x2 > 0) ? x2 - 1 : x2;
                break;
            case 'l': // move player2 right
                x2 = (x2 < 78) ? x2 + 1 : x2; // assuming console width is 80
                break;
            case 'q': // quit
                running = false;
                break;
            default:
                break;
            }

            // Clear current positions
            clearActors(actors);

            // Update positions
            player1.getSprite().moveTo(x1, y1);
            player2.getSprite().moveTo(x2, y2);

            // Move chaser towards player1
            moveChaser(chaser, x1, y1);

            // Draw updated positions
            drawActors(actors);
        }
        Sleep(50); // delay to reduce CPU usage
    }

    showCursor();
    return 0;
}
