#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    //Read price per pack
    
    cout << "Please enter the price for a six pack: ";
    double pack_Price;
    cin >> pack_Price;
    
    //Compute pack volume
    cout << "Please enter the volume for each can (in ouces): ";
    double can_Volume;
    cin >> can_Volume;
    
    const double CANS_PER_PACK = 6;
    double pack_Volume = can_Volume * CANS_PER_PACK;
    
    // Compute and print price per ounce
    double price_Per_Ounce =  pack_Price / pack_Volume;
    
    cout << fixed << setw(8);
    cout << "Price per ounce: " << price_Per_Ounce << endl;
    return 0;
 
}