#include "Sprite.h"

Sprite::Sprite(int width, int height, char fill)
{
	pixels.resize(height, std::vector<char>(width, fill));
	position = { 0,0 };
}

Sprite::~Sprite()
{
}

void Sprite::setPixel(int x, int y, char value)
{
	if (x >= 0 && x < pixels[0].size() && y >= 0 && y < pixels.size()) {
		pixels[y][x] = value;
	}
}

char Sprite::getPixel(int x, int y) const
{
	if (x >= 0 && x < pixels[0].size() && y >= 0 && y < pixels.size()) {
		return pixels[y][x];
	}
	return ' ';
}

void Sprite::draw() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int y = 0; y < pixels.size(); ++y) {
		for (int x = 0; x < pixels[y].size(); ++x) {
			COORD coord = { position.X + x, position.Y + y };
			SetConsoleCursorPosition(hConsole, coord);
			std::cout << pixels[y][x];
		}
	}
}

void Sprite::fill(char fill)
{
	for (auto& row : pixels) {
		std::fill(row.begin(), row.end(), fill);
	}
}

void Sprite::moveTo(int x, int y)
{
	clear();
	position.X = x;
	position.Y = y;
	draw();
}

void Sprite::clear() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int y = 0; y < pixels.size(); ++y) {
		for (int x = 0; x < pixels[y].size(); ++x) {
			COORD coord = { position.X + x, position.Y + y };
			SetConsoleCursorPosition(hConsole, coord);
			std::cout << ' ';
		}
	}
}

COORD Sprite::getPosition() const
{
	return this->position;
}
