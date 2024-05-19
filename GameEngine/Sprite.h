#ifndef SPRITE_H
#define SPRITE_H

#include<vector>
#include<string>
#include<iostream>
#include<windows.h>

class Sprite
{
public:
	Sprite(int width, int height, char fill = ' ');
	~Sprite();

	void setPixel(int x, int y, char value);

	char getPixel(int x, int y) const;

	void draw() const;

	void fill(char fill);

	void moveTo(int x, int y);

	void clear() const;

private:
	std::vector<std::vector<char>> pixels;
	COORD position;
};



#endif // !SPRITE_H
