#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

class User
{
public:
    //fuctions: Default constructor Set both title and author to empty strings
    User();
    User(string, int[], int);
    string getUsername();
    void setUsername(string);
    int getRatingAt(int);
    bool setRatingAt(int, int);
    int getNumRatings();
    void setNumRatings(int);
    int getSize();
    //int getUserReadCount(string);
    //g++ -std=c++11 Book.cpp Hmwk7.cpp
    
private:
    //data members 
    int size;
    string username;
    int ratings[200];
    int numRatings;
};
#endif
