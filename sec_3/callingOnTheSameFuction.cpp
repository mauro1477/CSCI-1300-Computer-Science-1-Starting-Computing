#include <iostream> 
using namespace std; 
// Declaration of cube_volume 

//The fuction is called as a header 
//Becuse its outside the main fuction
double cube_volume(double side_length);


int main()
{
    double result1 = cube_volume(2);
    // Use of cube_volume
    double result2 = cube_volume(10); 
    cout << "A cube with side length 2 has volume "<< result1<< endl;
    cout << "A cube with side length 10 has volume "<< result2<< endl; 
    return 0; 
    
} 
// Definition of cube_volume 

double cube_volume(double side_length) 
{
    return side_length * side_length * side_length;
    
}
