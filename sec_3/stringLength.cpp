#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string fname;
    string sname;
    cout << "Enter your first name: ";
    cin >> fname;
    cout << "Enter your significant other's first name: ";
    cin >> sname;
    string initials = fname.substr(0,1) + "&" + sname.substr(0,1);
    cout << initials;
    return 0;
 
}