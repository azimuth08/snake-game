#ifndef ENTITY_H_
#define ENTITY_H_

#include <cstdint>
#include <vector>
#include <main.h>


struct Position
{
    int x, y;
};

struct Color
{
    uint8_t R, G, B, A;

};

struct TextureSizing
{
    SDL_Rect textureSize = {32,32};
    Position center = { textureSize.w / 2, textureSize.h / 2 };
};

class Entity 
{
    public:
        struct Color color;
        Position position;

        Entity() :  color( {255, 255, 255, 255} ) , position( {0,0} ){};
        Entity(struct Position& p) : position( {0,0} ) , color( {255,255,255,255} ){};
        ~Entity();
        void setColor(struct Color& c);
};

#endif