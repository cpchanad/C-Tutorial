//This bring the iostream library
#include <iostream>
#include <string>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    short int a = 13;
    short int b = 23;

    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << endl;
    cout << a + b << endl;
    cout << sizeof(a + b) << endl;
    cout << endl;   

    int c = 0b11110;
    int d = 0b10010;
    int e = 0b00100;
    cout << c << endl;
    cout << d << endl;
    cout << (c & d) << endl; // and
    cout << (c | d) << endl; // or
    cout << (c ^ d) << endl; // xor
    cout << (c << 1) << endl; // *2
    cout << (d >> 1) << endl; // *1/2
    cout << (~e) << endl; //not i.e. reverse (sign bit also reversed to negative)
    // (~x) print out -(x-1)
    
    return 0;

}