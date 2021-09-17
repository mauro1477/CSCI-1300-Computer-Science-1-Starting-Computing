#include <iostream>
#include <math.h>

using namespace std;



int main ()
{
    double radius = 0;
    double  total, total2 = 0;
    cout << "Enter a radius: " << endl;
    cin >> radius;
    total = 4 * M_PI* pow(radius,2);
    total2 = 4* M_PI * ((pow(radius,3))/3);
    cout << "volume: "<< total2 << endl;
    cout << "surface area: " << total <<  endl;
}