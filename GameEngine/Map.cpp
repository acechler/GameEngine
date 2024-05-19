#include "Map.h"


// Constructor
Map::Map(int width, int height, char fillChar) {
    grid.resize(height, std::vector<char>(width, fillChar));
}

// Destructor
Map::~Map() {}

// Set character at a specific position
void Map::setChar(int x, int y, char value) {
    if (x >= 0 && x < grid[0].size() && y >= 0 && y < grid.size()) {
        grid[y][x] = value;
    }
}

// Get character at a specific position
char Map::getChar(int x, int y) const {
    if (x >= 0 && x < grid[0].size() && y >= 0 && y < grid.size()) {
        return grid[y][x];
    }
    return ' ';
}

// Draw the map
void Map::draw() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(hConsole, coord);

    for (const auto& row : grid) {
        for (const auto& ch : row) {
            std::cout << ch;
        }
        std::cout << std::endl;
    }
}

// Fill the map
void Map::fill(char fillChar) {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), fillChar);
    }
}

// Move a sprite within the map
void Map::moveSprite(int oldX, int oldY, int newX, int newY, char spriteChar) {
    setChar(oldX, oldY, ' '); // Clear the old position
    setChar(newX, newY, spriteChar); // Set the new position
    draw(); // Redraw the map
}
