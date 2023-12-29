//This bring the iostream library
#include <iostream>
#include <string>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    int max;
    int a = 30;
    int b = 50;

    max = (a >= b) ? a : b; //option1 & option2 must be same type or convertible
    // because they are declare as int
    cout << max << endl;
    //is the same as the following
    if (a >= b){
        max = a;
    }else{
        max = b;
    }
    cout << max << endl;

    bool fast = false;

    int speed = (fast) ? 300 : 150; //Ternary Initialization
    cout << speed << endl;

    auto max1 = (a >= b) ? a : 22.5; // auto: auto declare the type (but no string allow)
    // implicit declare
    cout << max1 << endl;

    return 0;

}