#include <iostream>
#include <string>
using namespace std;

int main() 
{
    cout << "Please enter your first name: ";
    string fname;
    cin >> fname;
    cout << "Please enter your last name: ";
    string lname;
    cin >> lname;
    cout << fname + " " + lname;
    return 0;
 
}