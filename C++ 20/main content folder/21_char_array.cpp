//This bring the iostream library
#include <iostream>
#include <string>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    char scores[] {'A','S','S','H','O','L','E'};
    for(auto c : scores){
        cout << c;
    }
    cout << endl;

    // is the same as the following

    //c string = array have null termination '\0'
    char scores_2[] {'A','S','S','H','O','L','E','\0'}; // Null termination:'\0' tell C++ to stop
    cout << scores_2 << endl; //for char array only

    // is the same as the following

    char scores_3[8] {'A','S','S','H','O','L','E'};
    cout << scores_3 << endl; //for char array only

    // is the same as the following

    char scores_4[] {"ASSHOLE IS YOU!"}; // string literal: auto added '\0' at the end (double quote)
    cout << scores_4 << endl; //for char array only
    cout << size(scores_4) << endl;

    scores_4[2] = {'d'};             //can change data one by one
    // scores_4 = {"dsfhdhg"} -> error cannot change data in one go because its an array

    //char pointer
    const char *p_char {"Hello World! I am Maya."};
    cout << p_char << endl;        //(pointer) print the whole message
    cout << *p_char << endl;       //print the first letter
    cout << p_char[2] << endl;     //print the 3rd postion character
    cout << *(p_char + 2) << endl; //print the 3rd postion character
    cout << p_char + 2 << endl;    //pointer = starting from 3rd positon

    p_char = p_char + 5;          //can change pointer point to somewhere (to other c-string)
    p_char = {"this is no good"}; //can change because pointer are not const
    //*p_char = 'G';       error -> cannot change because data are const

    const char *test {"this is not good."};
    const char *test_2 {test};

    test = {"these is bad."};
    cout << test << endl;  //test changed
    cout << test_2 <<endl; //test_2 remain unchange

    return 0;

}