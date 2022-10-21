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
    cout << "please input a number between 0 to 100: ";
    cin >> b;

    // if statement
    if(b > a){
        cout << "You are safe" << endl;
    }else if(b == a){
        cout << "You are barely safe" << endl;
    }else{
        cout << "You are fxxk" << endl;
    }

    return 0;

}