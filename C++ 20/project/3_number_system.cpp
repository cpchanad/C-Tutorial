//This bring the iostream library
#include <iostream>
#include <string>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    int a = 15;     //decimal     DEC 10
    int b = 017;    //Octal       OCT 8
    int c = 0x0f;   //Hexadecimal HEX 16
    int d = 0b1111; //Binary      BIN 2

    cout << "Hello World!" << endl;
    cout << "Number 1 is " << a << endl;
    cout << "Number 2 is " << b << endl;
    cout << "Number 3 is " << c << endl;
    cout << "Number 4 is " << d << endl;
    
    return 0;

}