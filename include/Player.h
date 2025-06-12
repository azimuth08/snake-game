#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <Entity.h>


class Player : public entity
{
    private:
        int length;

    public:
        Player(struct Position initPos, struct Color sColor);
        ~Player();
        void addLength();
        int getLength();
        

        
};

#endif