//This bring the iostream library
#include <iostream>
#include <string>
#include <math.h>
#define PI 3.14159265
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    //floor
    cout << floor(7.7) << endl;
    //ceil
    cout << ceil(7.7) << endl;

    //abs
    cout << abs(-23) << endl;

    //exp: e^2
    cout << exp(2) << endl;

    //pow: 3^4
    cout << pow(3,4) << endl;

    //log defalut:e
    cout << log(80) << endl;
    cout << log10(1000) << endl;

    //sqrt
    cout << sqrt(81) << endl;

    //rounded to nearest integer
    cout << round(2.5) << endl;

    //sin/cos/tan/asin/acos/atan
    cout << sin(PI/4) << endl;
    cout << cos(PI/4) << endl;
    cout << tan(PI/4) << endl;
    cout << asin(1) << endl;
    cout << acos(0) << endl;
    cout << atan(1) << endl;

    return 0;

}