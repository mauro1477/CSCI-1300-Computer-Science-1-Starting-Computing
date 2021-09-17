#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
   const int PENNIES_PER_DOLLAR = 100;
   const int PENNIES_PER_QUARTER = 25;
   
   cout << "Enter bill value (1 = $1 bill, 5 = $5 bill, etc): ";
   int bill_value;
   cin >> bill_value;
   cout << "Enter item price in pennies: ";
   int item_Price;
   cin >> item_Price;
   
   int change_due = PENNIES_PER_DOLLAR * bill_value - item_Price;
   int dollar_coins = change_due / PENNIES_PER_DOLLAR;
   
   change_due = change_due % PENNIES_PER_DOLLAR;
   int quarters = change_due / PENNIES_PER_QUARTER;
   // Gives five spaces before the number is printed
   cout << "Dollar coins: " << setw(6) << dollar_coins << endl
   << "Quarters: " << setw(6) << quarters << endl;
   
    return 0;
 
}