#include <iostream>
using namespace std;

int main() 
{
   int tileArea, numberOfTiles = 0;
   int totalArea = 0;
   int length, width = 0;
   //Ask the user to enter the lenght and width 
   cout << "Your task is to tile a rectangular bathroom floor with alternating black and white tiles measing 4 * 4 inches."<<endl;
   cout << "Enter lenght (in inches): "<<endl;
   cin >> length;
   cout << "Enter width (in inches): " <<endl;
   cin >> width;
   totalArea = length * width;
   numberOfTiles = totalArea/16;
   
   for (int counter = 1; counter <= numberOfTiles; counter++)
   {
      if ( counter % 2 == 0   )
   {
      cout << "Tile: " << counter << ". Place white tile. " <<endl; 
   }
      else
   {
        cout << "Tile: " << counter << ". Place black tile. " <<endl; 
   }
   cout << "The floor is complete. " <<endl; 
   }
   
}