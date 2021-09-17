#include <iostream>
#include <iomanip>

using namespace std;

void classGreeting(double PricePerOunce1) 
{
     cout << fixed <<setprecision(2); 
     cout << "Price per ounce: ";
     cout << PricePerOunce1;
}

int main ()
{
   double PricePerOunce = 0.0409722;
   classGreeting(PricePerOunce);
}