#include <iostream>
#include <string>
using namespace std;

//Function template
//set up a function blueprint, generate a function when it get called
//Use to solve code repetition, when the functions have the same function body

/*
Function blueprint

template <typename T> T maximum(T a, T b){
    return (a > b)? a : b;
}

its just a blueprint and not real C++ code consumed by the compiler
the compiler generate real C++ code when you call the function template
*/

//declare function template
template <typename T> T maximum(T a, T b);

int main(){

    int a {10};
    int b {23};

    double c {12.5};
    double d {11.2};

    string e {"Hello"};
    string f {"World"};
                                                  //generated function is called template instance
    cout << "int: " << maximum(a,b) << endl;      //passing int variables will create int argument function
    cout << "double: " << maximum(c,d) << endl;   //passing double variables will create double argument function
    cout << "string: " << maximum(e,f) << endl;   //passing string variables will create string argument function
    cout << endl;

    cout << "Int: " << maximum(3,5) << endl;      //same template instance only created once and will reuse the same
    cout << endl;

    int *p_a {&a};
    int *p_b {&b};
    cout << "pointer: " << maximum(p_a,p_b) << endl;  //comparing pointer (passing int pointer into function template)

    return 0;

}

//define dunction template
template <typename T> T maximum(T a, T b){
    return (a > b)? a : b;
}