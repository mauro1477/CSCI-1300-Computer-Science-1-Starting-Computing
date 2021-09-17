#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int floor;
    cout <<  "Floor: ";
    cin >> floor;
    int actual_Floor;
    if (floor > 13)
    {
        actual_Floor = floor - 1;
    }
    else
    {
        actual_Floor = floor; 
    }
    
    cout << "The elevator will travel to the actual floor " << actual_Floor << endl;
    return 0;
    
}