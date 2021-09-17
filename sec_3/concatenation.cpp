#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string fname = "Harry";
    string lname = "Morgan";
    string name = fname + lname;
    cout << name << endl; 
    
    string name2 = fname + " " + lname;
    cout << name2;
    return 0;
 
}