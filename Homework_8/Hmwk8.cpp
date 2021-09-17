// CSCI1300 Fall 2018
// Author: Mauro Vargas Jr 
// Recitation: 103 – Parajot Singh
// Cloud9 Workspace Editor Link:  https://ide.c9.io/mauro1477/project1 
// hmwk8 / Project2
// g++ -std=c++11 Book.cpp User.cpp Hmwk7.cpp
// zip Hmwk7.zip Book.cpp Book.h User.cpp User.h Hmwk7.cpp 
#include "Book.h"
#include "User.h"
#include "Library.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
using namespace std;

/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
 void displayMenu()
 {
     cout << "Select a numerical option:" << endl;
     cout << "======Main Menu=====" << endl;
     cout << "1. Read book file" << endl;
     cout << "2. Read user file" << endl;
     cout << "3. Print book list" << endl;
     cout << "4. Find number of books user rated" << endl;
     cout << "5. Get average rating" << endl;
     cout << "6. Add a User" << endl;
     cout << "7. Checkout a book" << endl;
     cout << "8. View Ratings" << endl;
     cout << "9. Get Recommendations" << endl;
     cout << "10. Quit" << endl;
 }



int main(int argc, char const *argv[])
{
   //Create object
    Book books[200];
    User users[200];
    Library x;
    //int index;
    string choice;
    int numBooks = 0;
    int numUsers = 0;
    //fuction1
    int numberOfBooks = 0;
    //int size = 200;
    string filename1 = "books.txt";
    //function2.
    int current_Size = 0;
    //int ratings[100][50]; 
    //string username[100];
    string filename2 = "ratings.txt";
    //fuction 3
    string titleOfBook[200];
    string authors[200];
    //fuction 4
    string userName;
    string title;
    string newRating;
    bool condition;
    int readBooksByUser = 0;
    double calAvg = 0;
    while (choice != "10") 
    {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) 
            {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    getline(cin, filename1);
                    numBooks = x.readBooks(filename1);
                    if(numBooks == -1)
                    {
                        cout << "No books saved to the database"<< endl;
                    }
                    if(numBooks > 0)
                    {
                        cout << "Total books in the database: " << numBooks << endl;
                    }
                    cout << endl;
                    break;

                case 2:
                    // read user file
                    cout << "Enter a rating file name:" << endl;
                    getline(cin, filename2);
                    numUsers = x.readRatings(filename2);
                    if (numUsers == -1)
                    {
                        cout << "No users saved to database" << endl;
                        //return -1;
                    }
                    else
                    {
                        cout << "Total users in the database: " << numUsers << endl;
                    }
                    cout << endl;
                    break;

                case 3:
                    // print the list of the books
                    x.printAllBooks();
                    break;

                case 4:
                    // getUserReadCount(userName, username, ratings, numUsers, numBooks);
                    // find the number of books user read
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
                    readBooksByUser =  x.getCountReadBooks(userName);
                    //cout << readBooksByUser << endl;
                    if(readBooksByUser == -1 || readBooksByUser == -2)
                    {
                        break;
                    }
                    else
                    {
                        cout << userName << " rated " << readBooksByUser << " books";
                        cout << endl;
                    }
                   

                case 5:
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;
                    getline(cin, title);
                    calAvg = x.calcAvgRating(title);
                    if(calAvg == -2 || calAvg == -1 || calAvg == 0)
                    {
                        break;
                    }
                    // else if(calAvg == -1)
                    // {
                    //     cout << "Database has not been fully initialized" << endl;
                    //     cout << endl;
                        
                    // }
                    else
                    {
                        cout << "The average rating for " << title << " is " << fixed << setprecision(2) << calAvg << endl;
                    }
                    cout << endl;
                    break;
                    
                case 6:
                    // add user
                    cout << "Enter username: " << endl;
                    getline(cin, userName);

                    condition = x.addUser(userName);
                    if(condition == true)
                    {
                        // If the user has successfully been added to the database
                        cout << "Welcome to the library " << userName << endl;
                        cout << endl;
                    }
                    else if(condition == false)
                    {
                        //If the user was not added to the database, print: 
                        cout << userName << " could not be added in the database" <<endl;
                        cout << endl;
                    }
                    break;
                    
                case 7:
                    // The member function checkOutBook updates the rating of the book for the user. This function should: 
                    bool condition;
                    
                    cout << "Enter username: " << endl;
                    getline(cin, userName);
                    // for(int i = 0; i < userName.length(); i++)
                    // {
                    //     userName[i] = tolower(userName[i]);
                    // }
                    cout << "Enter a book title: " << endl;
                    getline(cin, title);
                    cout << "Enter a rating for the book: " << endl;
                    getline(cin, newRating);
                    condition = x.checkOutBook(userName, title, stoi(newRating));
                    // If the book has successfully been read and rated
                    // If the book has not successfully been read and rated
                    if(condition == true)
                    {
                        cout << "We hope you enjoyed your book. The rating has been updated" << endl;
                    }
                    else
                    {
                        cout << userName << " could not check out "<< title << endl;
                    }
                    break;
                    
                case 8:
                    // prints all the books a user has provided ratings for
                    cout << "Enter a username: " << endl;
                    getline(cin, userName);
                    x.viewRatings(userName);
                    break;
                    
                case 9:
                    // get recommendatons
                    cout << "Enter a username: " << endl;
                    getline(cin, userName);
                    x.getRecommendations(userName);
                    break;
                    
                case 10:
                    // quit
                    cout << "good bye!" << endl;
                    break;
                    
                default:
                    cout << "invalid input" << endl;
                    cout << endl;
                    break;
            }
    }
    return 0;
}