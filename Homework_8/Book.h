#include <string>
#ifndef BOOK_H
#define BOOK_H
using namespace std;

/**
    
*/
class Book
{
public:
    //fuctions: Default constructor Set both title and author to empty strings
    Book();
    Book(string, string);
    // ~Book();
    //fuctions
    string getTitle();
    void setTitle(string);
    string getAuthor();
    void setAuthor(string);
    
    
private:
     //data members 
    string title;
    string author;
};
#endif
