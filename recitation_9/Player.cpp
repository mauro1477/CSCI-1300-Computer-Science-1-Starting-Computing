#include "Player.h"

Player::Player(int nDice)
{
    for (int i = 0; i < nDice; i++)
    {
        Dice d1;
        myDice[i] = d1;
        /*
        add Dice object created to array of Dices
        */
    }
}

void Player::setNumDice(int number)
{
    nDice = number;
}

void Player::playerRoll()
{
    int k = 0;
    for(int i = 0; i < nDice; i++)
    {
        myDice[i].roll();
    }
    //complete function to roll all the dices
    
}

int Player::getDiceValueAtIndex(int i)
{
    return myDice[i].getFaceValue();
}