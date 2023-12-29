#include <iostream>
#include <string>
using namespace std;

    /*
    One definition rule
    A definition cannot be show up more than once in the entire C++ program
                                     STU DTU     *TU = Translation unit (cpp file) . S = same . D = different
    1. Free standing variables        X   X      *X = redefinition not allowed 
    2. Functions                      X   X      *T = redefinition allowed
    3. Classes                        X   T
    4. Class member functions
    5. Class static member variable
    */

//Free standing variables: Declaration & definition
double weight {};     //redefinition of 'weight' in the same translation unit (here, this cpp file)
                      //or in different traslation units (other cpp files) are not allowed

//Functions
double add(double a, double b);    //redefinition of 'add' function are not allowed in both same or different translation unit

//Classes
struct Point                       //redefinition of 'Point' class are allowed in different traslation units (other cpp files)
{                                  //but not in the same translation unit (here, this cpp file)
    double m_x {2};
    double m_y {3};
};


int main(){

    cout << weight << endl;

    cout << add(3.4, 8.5) << endl;

    Point p1;
    cout << p1.m_x << endl;
    cout << p1.m_y << endl;

    return 0;

}

double add(double a, double b){
    return a + b;
}