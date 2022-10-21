//This bring the iostream library
#include <iostream>
#include <string>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    bool a = true;
    bool b = false;

    cout << a << endl;  //print 1
    cout << b << endl;  //print 0

    cout << boolalpha; //force the output to true/false
    cout << a << endl;  //print true
    cout << b << endl;  //print false

    
    return 0;

}