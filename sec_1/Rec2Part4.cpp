#include <iostream>


using namespace std;

void classGreeting(int number1) 
{
   cout << "Hello, CS "<< number1 << " World!" << endl; 
}

int main ()
{
   int number = 0;
   cout << "Enter a CS course number "; 
   cin >> number;
   classGreeting(number);
}