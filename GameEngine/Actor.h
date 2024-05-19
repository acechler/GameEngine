#ifndef ACTOR_H
#define ACTOR_H

#include<iostream>
#include<string>
#include"Sprite.h"

class Actor
{
public:
	Actor(std::string name, const Sprite& sprite);
	~Actor();

	// Getter for sprite
	Sprite& getSprite();       // Returning by reference to allow modification
	const Sprite& getSprite() const; // Const version for read-only access

	// Getter for name
	std::string getName() const;


private:
	Sprite sprite;
	std::string name;

};



#endif // !ACTOR_H