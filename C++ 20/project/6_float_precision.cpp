//This bring the iostream library
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    float a {3.523f}; //f indicate float
    double b {3.1234567890}; //default 
    long double c {2.447293073025702457070525L}; //L indicate long double
    double d {1.345e8}; //Scientific Notation
    cout << setprecision(20);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;

    return 0;

}