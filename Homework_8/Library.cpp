#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Library.h"
#include "Book.h"
#include "User.h"
using namespace std;
//split function for readBooks
int split(string str, char delim, string arr[], int size){
    stringstream ss(str);
    string tmp;
    int count = 0;
    while(getline(ss, tmp, delim)){
        if(count == size)
            return -1;
        else{
            arr[count] = tmp;
            count++;
        }
    }
    return count;
}

//fuctions: Default constructor Set both numBooks and numUsers to zero
Library::Library()
{
    numBooks = 0;
    numUsers = 0;
}

// implementation file
int Library::readBooks(string filename1)
{
   //declare variables
    string line = "";
    //open file
    ifstream myfile; 
    myfile.open(filename1);
    if(myfile.is_open())
    {
        while (numBooks < sizeBook && getline(myfile, line))// if numBooks is more then 200 return 
        {
            string parts[2];
            if(line.empty() || split(line, ',', parts, 2) != 2)// split file for books and aurthors
                continue;
            
            books[numBooks].setAuthor(parts[0]); // set authors
            books[numBooks].setTitle(parts[1]);// set titles
            numBooks++;
        }
    }
    else
    {
        //cout << "No books saved to the database"<< endl;
        return -1;
    }
    return numBooks;
}



int Library::readRatings(string filename2)
{
    int counterRatings = 0;
    int counterUsers = numUsers;
    string line = "";
    string line2 = "";
    //open file
    ifstream  filenameUsername; 
    filenameUsername.open(filename2);
    if(filenameUsername.is_open())
    {
        while (getline(filenameUsername, line))
        {
            // initionalize back to zero to get the correct count
           
            for(int i = 0; i < line.length(); i++)
            {
                
                if(line[i] == ',')
                {
                    //Read line serparate by "," names and ratings
                    users[counterUsers].setUsername(line.substr(0, i)); //setUsernames
                    cout << users[counterUsers].getUsername() << "..." << endl;//print usernames
                    users[counterUsers].setUsername(line.substr(0, i)) ;//set user name
                    line2 = line.substr(i + 1, (line.length() - 1) - i);
                    for(int j = 0; j < line2.length(); j++)
                    {
                        if(line2[j] != ' ')
                        {
                            //covert string ratings into real numbers
                            users[counterUsers].setRatingAt(counterRatings, stoi(line2.substr(j, 1)));// set ratings and stoi numbers from file
                            counterRatings++;//count ratings
                        }
                    }
                }
                counterRatings = 0;
        }
        counterUsers++;
        numUsers++;
        if(counterUsers  == sizeUser)// if users is more then 200 return count
        {
            return counterUsers;
        }
        }
    }
    else
    {
        
        return -1;
    }
    numUsers = counterUsers;//set counterUsers to numUsers to get the correct count
    return counterUsers;
}

//print all books in file
void Library::printAllBooks()
{
    if(numBooks == 0 && numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        cout << endl;
        //return -1;
    }
    else if(numBooks != 0)
    {
        cout << "Here is a list of books" << endl;
        for(int i = 0; i < numBooks; i++)
        {
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;// print titles and authors
        }
        cout <<endl;
    }
    else
    {
        cout << "No books are stored" << endl;
        cout << endl;
    }
}
int Library::getCountReadBooks(string username)
{
     // call helper function
     //cout << "In getCountReadBooks." << endl;
     //cout << numUsers << endl;
     
    int index = helperFuctionToFindUsers(username);// find index for the username entered
    
    //cout << index << endl;
    if(numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        cout << endl;
        return -1;
    }
    if(index == - 1)
    {
        cout << username << " does not exist in the database" << endl;
        cout << endl;
        return -2;
    }
    else if(numBooks != 0 && index != 0)
    {
        int counter = 0;
        for(int i = 0; i < numBooks; i++)
        {
            if(users[index].getRatingAt(i) != 0) // count number of rates for the user entered
            {
                counter++;
            }
        }
        return counter;
    }
}
double Library::calcAvgRating(string titleOfBook)
{
    // call helper function
    int index = helperFuctionToFindTitles(titleOfBook);

    double sum = 0;
    double avg = 0;
    double counter = 0;
    //cout << index << endl;
    if(numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        cout << endl;
        return -1;
    }
    else if (index == -1)
    {
        cout << "this book does not exist in the database" << endl;
        cout << endl;
        return -2;
    }
    else
    {
        for(int i = 0; i < numUsers; i++)
        {
            if(users[i].getRatingAt(index) != 0.00)
            {
                sum += users[i].getRatingAt(index);
                counter++;
            }
        }
        avg = sum/counter;
        return avg;
        //cout << "The average rating for " << titleOfBook << " is " << fixed << setprecision(2) << avg << endl;
    }
}

bool Library::addUser(string username)
{
    string OG = username;
    // turn username entered into lower cases
    for(int i = 0; i < username.length(); i++)
    {
        username[i] = tolower(username[i]);
    }
    //see if user already exist in the database
    int indexUser = helperFuctionToFindUsers(username);
    //cout << indexUser << endl;
    if(indexUser > 0)// if the number is higher then zero the name is already in the database else it will return -1 and it will be added
    {
        cout << OG << " already exists in the database" << endl;
        //cout << endl;
        return false;
    }
    if(numUsers == 200)// if number of users is equal to 200 the data base is full 
    {
      cout << "Database full" << endl;
      return false;
    }
    else 
    {
        // create a object
        User object1;
        object1.setUsername(OG);//set name entered by user 
        users[numUsers] = object1;// add new user to number of users
        numUsers++;// add one new user
        return true;
    }
}


bool Library::checkOutBook(string username, string title, int newRating)
{
    
    bool condition = false;// set to false to enter to check for cases
    // Find the index of the user and the index for the book
    int indexUser = helperFuctionToFindUsers(username);
    int indexBook = helperFuctionToFindTitles(title);
    //If the program has not read any books files or any ratings files
    //cout << indexUser << endl;
    if(condition == false)
    {
        if(numBooks == 0 || numUsers == 0)
        {
            cout << "Database has not been fully initialized" << endl;
            return false;
        } 
        //check for user
        if(indexUser < 0)
        {
            cout << username << " does not exist in the database" << endl;
            condition = false;
        } 
         //check for book
        if(indexBook < 0)
        {
            cout << title << " does not exist in the database" << endl;
            condition = false;
        } 
        if(!(newRating >= 0 && newRating <= 5))// if the rating entered is not between 0-5 print not valued
        {
            cout << newRating << " is not valid" << endl;
            return false;
        }
    }
    else
        {
        for (int i = 0; i < numUsers; i++)
        {
            if(users[i].getUsername() != " ")//else 
            {
                //set new rating
                condition = users[indexUser].setRatingAt(indexBook, newRating);
            }
        }
     return condition;
    }
  
}
void Library::viewRatings(string username)
{
    
    //viewRatings prints all the books a user has provided ratings
    int indexUser = helperFuctionToFindUsers(username);
    int booksRead = getCountReadBooks(username);
     //int indexBook = helperFuctionToFindTitles(title);
    if(numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
        return;
    }
    if(indexUser == -1)
    {
        //cout << username << " does not exist in the database" << endl;
        return;
    } 
    if(booksRead == 0)
    {
        cout << username << " has not rated any books yet";
        return;
    }
    else
    {
        cout << "Here are the books that " << username << " rated" << endl;
        //goes through number of ratings
        for(int k = 0; k < numBooks; k++)
        {
            if(users[indexUser].getRatingAt(k) > 0)
            {
                //Print books readed by user
                cout << "Title : " << books[k].getTitle() << endl;
                cout << "Rating : " << users[indexUser].getRatingAt(k) << endl;
                cout << "-----" << endl;
            }
        }
    }
}

void Library::getRecommendations(string username)
{
    //The member function getRecommendations will recommend book titles a user might
    //enjoy, based on the user’s similarity of ratings with another user.
    int indexUser = helperFuctionToFindUsers(username);
    if(numBooks == 0 || numUsers == 0)
    {
        cout << "Database has not been fully initialized" << endl;
         cout << endl;
        return;
    }
    if(indexUser == -1)
    {
        cout << username << " does not exist in the database" << endl;
        cout << endl;
        return;
    } 
    
}

//find user
int Library::helperFuctionToFindUsers(string userName)
{
    int index = -1;
    for(int i = 0; i < numUsers; i++)
    {
        if(users[i].getUsername() == userName)
        {
            index = i;
        }
    }
    return index;
}

 //find title 
int Library::helperFuctionToFindTitles(string titles)
{
    int index = -1;
    for(int i = 0; i < numBooks; i++)
    {
        if(books[i].getTitle() == titles)// match
        {
            index = i;
        }
    }
    return index;
}