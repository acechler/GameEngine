// GameEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sprite.h"

int main()
{
    std::cout << "Hello World!\n";
    
    Sprite sprite(2, 2);
    sprite.setPixel(0, 0, '#');
    sprite.setPixel(1, 0, '#');
    sprite.setPixel(0, 1, '#');
    sprite.setPixel(1, 1, '#');

    sprite.draw();
}

