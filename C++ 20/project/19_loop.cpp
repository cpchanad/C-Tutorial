//This bring the iostream library
#include <iostream>
#include <string>
#include <limits>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){
    // for loop
    const size_t COUNT = 10; //const: make the variable cannot be changed

    for(int i = 0; i < 3 ; ++i){
        cout << "Hello World!" << endl;
    }

    cout << endl;
    
    // size_t unsigned very large number (8bytes)
    for(size_t i = 0; i < COUNT ; i += 2){
        cout << "Hello World!" << endl;
    }
    cout << endl;
    cout << "size_t:" << endl;
    cout << "sizeof: " << sizeof(size_t) << endl;
    cout << "max: " << numeric_limits<size_t>::max() << endl;
    cout << "min: " << numeric_limits<size_t>::min() << endl;
    cout << endl;
    
    // while loop
    int j = 0;
    while(j < 3){
        cout << "Hello World!" << endl;
        j++;
    }
    cout << j << endl;

    cout << endl;

    // do while loop
    int k = 0;
    do{
        cout << "Hello World!" << endl;
        k++;
    }
    while(k < 3);
    cout << k << endl;

    cout << endl;

    return 0;

}