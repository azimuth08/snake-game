#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <Entity.h>


class Player : public Entity
{
    private:
        int length;

    public:
        Player() : Entity() , length(0) {};
        ~Player();
        SDL_Texture* head, body, tail;
        void addLength();
        int getLength();
        

        
};

#endif