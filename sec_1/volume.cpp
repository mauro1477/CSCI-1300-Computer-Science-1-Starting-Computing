#include <iostream>
using namespace std;
   /*
      This program computers the volume (in liters) of a six of soda
      cans and the total volume of a six packs and a two-liter bottle
   */
int main() 
{

    int cans_per_pack = 6;
    const double BOTTLE_VOLUME = 2; // Two-liter bottle
    const double CAN_VOLUME = 0.355; // Liters in a 12-ounce can 
    double total_volume = cans_per_pack * CAN_VOLUME;
    cout << "A six-pack of 12-ounce cans contain "
    << total_volume << "liters. " << endl;
    
  
    //The number is spite out and the varible is left empty, so it can be replace.
    
    total_volume = total_volume + BOTTLE_VOLUME; 
    cout << "A six-pack and a two-liter bottle contain "
    << total_volume << "liters. " << endl;
    //Why is the this zero here its the main funtion?
 
}