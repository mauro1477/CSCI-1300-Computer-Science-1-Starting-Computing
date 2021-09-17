#include <iostream>
#include <cmath>
using namespace std;

int totalCost(int numberParam, double priceParam)
{
    double subtotal;
    subtotal = priceParam * numberParam;
    
    double total;
    total = subtotal + subtotal * 0.5;
    return total;
}

int main() 
{
    double price, bill;
    int numberItems;
    cout << "Enter te number of items purchased: ";
    cin >> numberItems;
    cout << "Enter the price per items $";
    cin >> price;
    
    double total = totalCost(numberItems, price);
    total = totalCost(27, price);
    total = totalCost(numberItems, 5.75);
    
    cout << numberItems << " items at " << "$" << price << "each.\n";
    

}