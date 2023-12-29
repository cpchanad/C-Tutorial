//This bring the iostream library
#include <iostream>
#include <string>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    int a (15);  //Functional Initialization
    int b {30};  //Braced Initialization (best way)
    int c = 288; //Assignment Initialization

    // Size of a type in memory
    cout << a + b + c << endl;
    cout << sizeof(int) <<endl;
    cout << sizeof(double) <<endl;
    cout << sizeof(float) <<endl;
    cout << sizeof(bool) <<endl;
    cout << sizeof(string) <<endl;

    cout << "" << endl;

    cout << sizeof(a) <<endl;
    cout << sizeof(b) <<endl;
    cout << sizeof(c) <<endl;

    return 0;

}