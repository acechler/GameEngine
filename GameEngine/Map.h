#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <windows.h>


class Map {
private: 
	std::vector<std::vector<char>> grid;
	COORD position;


public:
	Map(int width, int height, char fillChar = ' ');

	~Map();

	void setChar(int x, int y, char value);

	char getChar(int x, int y) const;

	void draw() const;

	void fill(char fillChar);

	void moveSprite(int oldX, int oldY, int newX, int newY, char spriteChar);

};






#endif // !MAP_H
