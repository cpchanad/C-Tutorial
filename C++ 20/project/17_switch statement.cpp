//This bring the iostream library
#include <iostream>
#include <string>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){

    int a = 50;
    int b;
    cout << "Please input a number between 0 to 100: ";
    cin >> b;

    switch(b){ // b can only be number not string

        case 10:{
            cout << "10!bad!";
        }
        break; // tell C++ to break after excute case

        case 20:{
            cout << "20!bad!";
        }
        break; // tell C++ to break after excute case

        case 30:{
            cout << "30!bad!";
        }
        break; // tell C++ to break after excute case

        case 40:{
            cout << "40!bad!";
        }
        break; // tell C++ to break after excute case

        // multiple case
        case 55:
        case 50:{
            cout << "50!Good!";
        }
        break; // tell C++ to break after excute case

        case 60:{
            cout << "60!Good!";
        }
        break; // tell C++ to break after excute case

        case 70:{
            cout << "70!Good!";
        }
        break; // tell C++ to break after excute case

        case 80:{
            cout << "80!Exellent!";
        }
        break; // tell C++ to break after excute case

        case 90:{
            cout << "90!Exellent!";
        }
        break; // tell C++ to break after excute case

        case 100:{
            cout << "100!Perfect!";
        }
        break; // tell C++ to break after excute case

        default: {
            cout << "Please try again.";
        }

    }

    return 0;

}