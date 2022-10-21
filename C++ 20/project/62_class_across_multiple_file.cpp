#include <iostream>
#include <string>
#include "62_constants.h"   //include constant header file -> see for more info on #ifndef
#include "62_cylinder.h"    //include class header file
using namespace std;

//class across multiple file
//Constant PI are stored in constant.h header file
//Cylinder declaration in cylinder.h header file
//Cylinder definition in cylinder.cpp file

int main(){

    Cylinder cy1(10,10);
    cout << "V: " << cy1.volume() << endl;
    
    cout << TEST << endl;

    return 0;

}