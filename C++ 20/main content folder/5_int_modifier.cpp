//This bring the iostream library
#include <iostream>
#include <string>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    unsigned short int a = 132; //reduce int memory to 2
    signed long long int b = -244; //lengthen int memory to 8

    cout << a << endl;
    cout << sizeof(a) << endl;
    cout << b << endl;
    cout << sizeof(b) << endl;

    return 0;

}