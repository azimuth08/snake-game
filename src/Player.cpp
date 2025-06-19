#include "../include/Player.h"

Player::~Player()
{

}

void Player::addLength()
{
    length++;
}

int Player::getLength()
{
    return length;
}