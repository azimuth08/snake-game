#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <entity.h>


class player : public entity
{
    private:
        int length;

    public:
        player(struct Position initPos, struct Color sColor);
        ~player();
        void addLength();
        int getLength();
        

        
};

#endif