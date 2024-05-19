#include "Actor.h"

Actor::Actor(std::string name, const Sprite& sprite) : name(name), sprite(sprite)
{
}

Actor::~Actor()
{
}

// Getter for sprite
Sprite& Actor::getSprite() {
    return sprite;
}

const Sprite& Actor::getSprite() const {
    return sprite;
}


std::string Actor::getName() const
{
    return name;
}

