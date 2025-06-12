#ifndef ENTITY_H_
#define ENTITY_H_

#include <cstdint>
#include <vector>
struct Position
{
    int x, y;
};

struct Color
{
    uint8_t R, G, B, A;

};

class entity 
{
    public:

        struct Color color;
        std::vector<Position> position;

        entity(struct Position& );
        void setColor(struct Color& c);

};

#endif