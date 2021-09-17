// Mauro Varga Jr: CS1300 Fall 2018
// Recitation: 102 – Parajot Singh
// Cloud9 Workspace Editor Link: https://ide.c9.io/mauro1477/project1 
// Homework 2 - Problem #4
 
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;
double luminosity(double brightness1, double displays1)
{
    
    //declare variables
    double PI = 3.14159;
    double luminosityResult = 0;
    //Perform formula L = 4bPId^2
    luminosityResult = (4 * brightness1 *PI * pow(displays1, 2));
    int result = static_cast<int>(luminosityResult);
    return result;
   
}

int main() 
{
    //declare variables  
    double brightness, distance, result = 0;
    cout << "This program displays luminosity the total amount of energy emitted"
    << " per unit by a star, galaxy, or other astronomical object. \n"
    << "Calculate the luminosity of an object." << endl;
    cout << "Please enter brightness: ";
    cin >> brightness;
    cout << "Please enter distance: ";
    cin >> distance;
    result = luminosity(brightness, distance);
    cout << result ;
    
}
