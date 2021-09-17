#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"
using namespace std;
//fuctions: Default constructor Set both title and author to empty strings
Book::Book()
{
    title = "";
    author = "";
}
//fuctions: Parameterized constructor Takes two strings for initializting  title and author, in this order
Book::Book(string title1, string author1)
{
     title = title1;
     author = author1;
}

// implementation file
string Book::getTitle()
{
    return title;
}
//set titles
void Book::setTitle(string title1)
{
    title = title1;
}
//return author
string Book::getAuthor()
{
    return author;
}
// set author
void Book::setAuthor(string author1)
{
    author = author1;
}