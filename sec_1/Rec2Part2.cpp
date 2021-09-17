#include <iostream>
#include <math.h>

using namespace std;

void sphereVolume(double radius1)
{
     double  total2 = 0;
     total2 = 4* M_PI * ((pow(radius1,3))/3);
     cout << "volume: "<< total2 << endl;
}

int main ()
{
    double radius = 0;
    cout << "Enter a radius: ";
    cin >> radius;
    sphereVolume(radius);
}