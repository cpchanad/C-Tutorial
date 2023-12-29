#include <iostream>
#include <string>
using namespace std;

int main(){

    int a {45};
    double b {23.4};

    //reference: alias of the oringial and can be used just like the original
    int &r_a {a};    //reference through initialization
    double &r_b = b; //reference through assignment

    //value
    cout << a << endl;
    cout << r_a << endl;
    cout << b << endl;
    cout << r_b << endl;

    //address
    cout << &a << endl;
    cout << &r_a << endl;   //refernece and original have the same address
    cout << &b << endl;
    cout << &r_b << endl;

    //sizeof
    cout << sizeof(int) << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(r_a) << endl;     //refernece and original have the same size
    cout << sizeof(double) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(r_b) << endl;
    cout << endl;

    //change value through any variable will change the other one too
    r_a = 55;
    cout << a << endl;
    cout << r_a << endl;

    b = 33.4;
    cout << b << endl;
    cout << r_b << endl;

    return 0;

}