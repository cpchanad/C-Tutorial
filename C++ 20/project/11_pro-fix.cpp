//This bring the iostream library
#include <iostream>
#include <string>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    int a,b,c,d;

    a = 3;
    b = 7;

    //postfix increment/decrement
    cout << a++ << endl; //incrementing 3
    cout << a << endl;   //4

    cout << b-- << endl; //decrementing 7
    cout << b << endl;   //6

    //print "a" first then excute "++" to increase

    a = 3;
    b = 7;

    //prefix increment/decrement
    cout << ++a << endl; //incremented 4
    cout << a << endl;   //4

    cout << --b << endl; //decremented 6
    cout << b << endl;   //6

    //excute "++" to increase first then print "a"

    return 0;

}