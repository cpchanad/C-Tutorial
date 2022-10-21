//This bring the iostream library
#include <iostream>
#include <string>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    char a = 'a';
    char b = 97; // ASCII character code for a
    cout << a << endl;
    cout << b << endl;
    cout << static_cast<int>(a) << endl; //force to output ASCII code

    return 0;

}