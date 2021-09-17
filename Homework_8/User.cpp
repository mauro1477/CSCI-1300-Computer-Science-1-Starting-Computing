#include <iostream>
#include <iomanip>
#include "User.h"
using namespace std;
//Default constructor
User::User()
{
    username = "";
    numRatings = 0;
    size = 200;
    //set elements
    for(int i = 0; i < 200; i++ )
    {
        ratings[i] = -1;
    }
}
//Parameterized constructor
User::User(string username1, int ratings1[], int numRatings1)
{
    username = username1;
    numRatings = numRatings1;
    //traverse through array
    
    // init with -1s
    for(int i = 0; i < 200; i++ )
    {
        ratings[i] = -1;
    }
    // copying into array 
    for(int i = 0; i < numRatings1; i++)
    {
        //copy one for one
        ratings[i] = ratings1[i];
    }
   
}
//return username
string User::getUsername()
{
    return username;
}
//set username
void User::setUsername(string username1)
{
    username = username1;
}
//Returns the rating stored at the specified index.
//If index is larger than the size of the rating arry, return-1
int User::getRatingAt(int index1)
{
    if(index1 >= 200)
    {
        return -1;
    }
    else
    {
        return ratings[index1];
    }
}
//Sets the rating to value at the specified index, if index is within the bounds of the array and value is
//is between 0  and 5. Return a boolean, true if the rating is successfully update and false otherwise
bool User::setRatingAt(int index1, int value1)
{
    if((index1 >= 0 && index1 <= 200) && (value1 >= 0 && value1 <= 5))
    {
        ratings[index1] = value1; 
        return true;
    }
    else
    {
        return false;
    }
}
//return numratings
int User::getNumRatings()
{
    return numRatings;
}

//set numRatings
void User::setNumRatings(int input)
{
    numRatings = input;
}
//return size
int User::getSize()
{
    return size;
}
