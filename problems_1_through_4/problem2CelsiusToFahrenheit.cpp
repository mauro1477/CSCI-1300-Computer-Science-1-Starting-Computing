
// Mauro Varga Jr: CS1300 Fall 2018
// Recitation: 102 – Parajot Singh
// Cloud9 Workspace Editor Link: https://ide.c9.io/mauro1477/project1 
// Homework 2 - Problem #2
 
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void celsiusToFahrenheit(double celsius)
{
    double fahrenheit;
    //Covert celsius to fahrenheit.
    fahrenheit = celsius * 9/5  + 32;
    //Use setprecision(2) to display two figures after the decimal 
    cout << "The temperature of " << celsius << " in fahrenheit is " << fixed << setprecision(2) << fahrenheit << endl;
}

int main() 
{
    double userInput;
    cout << "This program converts Celsius to Fahrenheit. " << endl;
    cout << "Enter Celsius: ";
    cin >> userInput;
    celsiusToFahrenheit(userInput);
}
