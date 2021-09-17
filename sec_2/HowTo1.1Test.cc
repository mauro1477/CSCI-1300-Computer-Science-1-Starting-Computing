
#include <iostream>
using namespace std;

int main() 
{
   double purchasePrice1, purchasePrice2 = 0;
   double fuelEfficiency1, fuelEfficiency2 = 0;
   double operatingCost1, operatingCost2 = 0;
   double annualFuelConsumed1, annualFuelConsumed2 = 0;
   double annualFuelCost1, annualFuelCost2 = 0;
   double totalCost2, totalCost1 = 0;
   const double averageFuelCost = 4;
   const double annualMilesDriven = 15000;
   
   
   cout << "Enter the price of the first car: "<<endl;
   cin >> purchasePrice1;
   cout << "Enter fuel efficiency for the first car (in mpg): " <<endl;
   cin >> fuelEfficiency1;
   cout << "Enter the price of the secound car: " <<endl;
   cin >> purchasePrice2;
   cout << "Enter fuel efficiency for the first car (in mpg): " <<endl;
   cin >> fuelEfficiency2;
   
   annualFuelConsumed1 = annualMilesDriven/fuelEfficiency1;
   annualFuelConsumed2 = annualMilesDriven/fuelEfficiency2;
   annualFuelCost1 = averageFuelCost * annualFuelConsumed1;
   annualFuelCost2 = averageFuelCost * annualFuelConsumed2;
   operatingCost1 = 10 * annualFuelCost1;
   operatingCost2 = 10 * annualFuelCost2;
   totalCost1 = purchasePrice1 + operatingCost1;
   totalCost2 = purchasePrice2 + operatingCost2;
   
   if ( totalCost1 <  totalCost2 )
   {
        cout << "Choose car One for the better deal!" <<endl; 
        cout << "Total cost: " << totalCost1 <<endl; 
        cout << "OperatingCost1: " << operatingCost1 <<endl; 
        cout << "AnnualFuelCost1: " << annualFuelCost1 <<endl; 
   }
   else if ( totalCost1 >  totalCost2)
   {
        cout << "Choose car Two for the better deal!" <<endl;
        cout << "Total cost: " << totalCost2 <<endl; 
        cout << "OperatingCost2: " << operatingCost2 <<endl;
        cout << "AnnualFuelCost2: " << annualFuelCost2 <<endl; 
   }
}