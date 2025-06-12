#include "../include/Entity.h"

Entity::Entity(struct Position& position)
{
    this->position.push_back(position);

    struct Color defColor;
    defColor.R, defColor.G, defColor.B, defColor.A = 255;
    this->color = defColor;
}

Entity::~Entity()
{

}

void Entity::setColor(struct Color& c)
{
    this->color.R = c.R;
    this->color.G = c.G;
    this->color.B = c.B;
    this->color.A = c.A;

}