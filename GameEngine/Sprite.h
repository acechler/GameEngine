#ifndef SPRITE_H
#define SPRITE_H

#include<vector>
#include<string>
#include<iostream>

class Sprite
{
public:
	Sprite(int width, int height, char fill = ' ');
	~Sprite();

	void setPixel(int x, int y, char value);

	char getPixel(int x, int y) const;

	void draw() const;

	void fill(char fill);

private:
	std::vector<std::vector<char>> pixels;
};



#endif // !SPRITE_H
