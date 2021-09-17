
// Mauro Varga Jr: CS1300 Fall 2018
// Recitation: 102 – Your TA 
// Cloud9 Workspace Editor Link: https://ide.c9.io/mauro1477/project1 
// Homework 2 - Problem #1
 
#include <iostream>
#include <cmath>

using namespace std;

void convertSeconds(int userInput1)
{
    double hours = 0;
    double minutes = 0;
    double seconds = 0; 
    //convert the seconds into hours and minutes
    hours = userInput1 / 60 / 60; 
    minutes = (userInput1 / 60) % 60;
    seconds = userInput1 % 60;
    //display results
    cout << hours <<" hour(s) "<< minutes <<" minute(s) " << seconds << " second(s)" << endl;
}

int main() 
{
    int userInput;
    cout << "This program converts seconds into minutes and hours." << endl;
    cout << "Please enter the amout of seconds you wish to convert:";
    cin >> userInput;
    convertSeconds(userInput);
}
