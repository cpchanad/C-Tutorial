#include <iostream>
#include <string>
#include <concepts>
#include <math.h>
using namespace std;

//Concepts and auto

auto add(auto a, auto b){
    return a+b;
}

int main(){

    //enforce conecepts onto variables
    integral auto x = add(10,20);          //constrain declared auto var
    /*
    floating_point auto y = add(10,20);    //error -> deduced type int not satisfy concept
    */
   
    cout << x << endl;

    return 0;

}