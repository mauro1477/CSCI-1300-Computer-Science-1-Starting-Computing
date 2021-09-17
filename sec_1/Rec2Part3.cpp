#include <iostream>
#include <math.h>

using namespace std;

void sphereSurfaceArea(float radius)
{
    double  total = 0;
    total = 4 * M_PI* pow(radius,2);
    cout << "surface area: " << total << endl;
}

int main ()
{
    float radius = 0;
    cout << "Enter a radius: ";
    cin >> radius;
    sphereSurfaceArea(radius);
}