#include <iostream>
#include <string>
using namespace std;

//Function declaration & definition (2 parts)

//1. declare a function (function declaration)
int max(int a, int b);       //function header must be declared first before main() and then define here or later

int main(){

    int x {2};
    int y {9};

    cout << max(x,y) << endl;

    return 0;

}

//2. define a function (function implementation)
int max(int a, int b){       //function body with all the detail
    if(a>b){
        return a;
    }else{
        return b;
    }
}