//This bring the iostream library
#include <iostream>
#include <string>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    //declare array
    //array store data with the same type
    int scores[10];
    double test[5] {2.1,3.0,4.5}; // test[3][4] will have 0
    const int name[] {1,2,3,4,5,6,7,8,9,0}; // can omit size, but cannot declare alone

    cout << size(name) << endl; // get the size of an array
    cout << endl;

    for(size_t i = 0; i < 10; i++){
        scores[i] = 5*i;
    }

    for(size_t i = 0; i < 10; i++){
        cout << scores[i] << endl;
        cout << test[i/2] << endl;
    }
    
    // ranged base for loop
    for(auto value: name){
        cout << value << endl;
    }

    // for element in name[]:
    int sum = 0;
    for(int element: name){
        sum += element;
    }
    cout << sum << endl;

    return 0;

}