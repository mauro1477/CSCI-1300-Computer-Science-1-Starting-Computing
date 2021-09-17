#include <string>
#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "User.h"
using namespace std;

class Library
{
public:
    //fuctions: Default constructor sets both numBooks and numUsers to value 0
    Library();
    
    //fuctions
    int readBooks(string);
    int readRatings(string);
    void printAllBooks();
    int getCountReadBooks(string);
    double calcAvgRating(string);
    void getRecommendations(string);
    bool addUser(string);
    bool checkOutBook(string, string, int);
    void viewRatings(string);
    //extra helperFunction find Users and titles
    int helperFuctionToFindUsers(string);
    int helperFuctionToFindTitles(string);
    
private:
     //data members 
    Book books[200];
    User users[200];
    int numBooks;
    int numUsers;
    int sizeBook = 200;
    int sizeUser = 200;
    
};
#endif
