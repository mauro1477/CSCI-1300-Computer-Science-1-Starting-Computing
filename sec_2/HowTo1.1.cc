#include <iostream>
using namespace std;

int main() 
{
   int purchasePrice1 = 0;
   int purchasePrice2 = 0;
   int fuelEfficiency1 = 0;
   int fuelEfficiency2 = 0;
   int operatingCost1 = 0;
   int operatingCost2 = 0;
   
   
   cout << "Enter the price of the first car: "<<endl;
   cin >> purchasePrice1;
   cout << "Enter fuel efficiency for the first car (in mpg): " <<endl;
   cin >> fuelEfficiency1;
   cout << "Enter the price of the secound car: " <<endl;
   cin >> purchasePrice2;
   cout << "Enter fuel efficiency for the first car (in mpg): " <<endl;
   cin >> fuelEfficiency2;
   
   operatingCost1 = 10 * fuelEfficiency1;
   operatingCost2 = 10 * fuelEfficiency2;
   
   if (operatingCost1 < operatingCost2)
   {
        cout << "Choose car One for the better deal!" <<endl; 
   }
   else if (operatingCost1 > operatingCost2)
   {
        cout << "Choose car Two for the better deal!" <<endl; 
   }
}