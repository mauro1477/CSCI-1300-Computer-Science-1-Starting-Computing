
// Mauro Varga Jr: CS1300 Fall 2018
// Recitation: 102 – Parajot Singh
// Cloud9 Workspace Editor Link: https://ide.c9.io/mauro1477/project1 
// Homework 2 - Problem #3
 
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int population(int userInput)
{
    //inititinalize variables
    int resultEightSeconds, resultTwelveSeconds, resultTwentySeven = 0;
    int population, final, answer, subrationToPopulation, additionToPopulation = 0;
    //This is the number of seconds in a year;
    int year = 31536000
    //Divide a year by all the different times given
    resultEightSeconds = year / 8;
    resultTwelveSeconds = year / 12;
    resultTwentySeven = year / 27; 
    //Add the new immigrants and the new borns together
    additionToPopulation = resultEightSeconds + resultTwentySeven;
    subrationToPopulation = resultTwelveSeconds; 
    //subract the deaths
    answer = additionToPopulation - subrationToPopulation;
    //Add to populaton 
    final = answer + userInput; 
    //display final answer
    cout << final; 
}

int main() 
{
    int userInput;
    cout << "This program calculates the U.S population in exaxtly one year (365 days). \n ";
    cout << "Rates below apply: \n";
    cout << "a. There is a birth every 8 seconds.\n";
    cout << "b. There is a death every 12 seconds. \n";
    cout << "c. There is a new immigrant arriving in the US every 27 seconds.\n";
    cout << "Enter current U.S population: ";
    cin >> userInput;
    population(userInput);
}
