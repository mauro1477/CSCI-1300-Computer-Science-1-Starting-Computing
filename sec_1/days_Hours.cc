#include <iostream>
using namespace std;

int main() 
{
   int seconds, numberOfDays, numberOfHours, numberOfMinutes, numberOfSeconds = 0;
   cout << "Enter the number of seconds: "<<endl;
   cin >> seconds;
 
   numberOfDays = seconds/86400;
   numberOfHours = (seconds%86400)/3600;
   numberOfMinutes = ((seconds%86400)%3600)/60;
   numberOfSeconds = ((seconds%86400)%3600)%60;

   cout << "Days: " << numberOfDays <<endl; 
   cout << "Hours: " << numberOfHours <<endl; 
   cout << "Minutes: " << numberOfMinutes <<endl; 
   cout << "Seconds: " << numberOfSeconds <<endl; 
  
}