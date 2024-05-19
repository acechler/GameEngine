#include "Sprite.h"

Sprite::Sprite(int width, int height, char fill)
{
	pixels.resize(height, std::vector<char>(width, fill));
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
	// SetCursorPosition
	for (const auto& row : pixels) {
		for (const auto& pixel : row) {
			std::cout << pixel;
		}
		std::cout << std::endl;
	}
}

void Sprite::fill(char fill)
{
	for (auto& row : pixels) {
		std::fill(row.begin(), row.end(), fill);
	}
}
