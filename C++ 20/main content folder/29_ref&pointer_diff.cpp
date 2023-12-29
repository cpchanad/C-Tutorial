#include <iostream>
#include <string>
using namespace std;

int main(){

    //differences bewteen reference and pointer
    //1. no dereference operator & dereference operator to gain access to value
    //2. cannot change to reference something else & can point to somewhere else
    //3. initialized at declaration & can be declared un-initialized

    double value {3.14};

    double &ref_value {value};

    double *p_value {&value};         //not store in heap
    double *const p_value_2 {&value}; //constant pointer cannot be point to other value

    cout << value << endl;
    cout << &value << endl;
    cout << endl;
    cout << ref_value << endl;
    cout << &ref_value << endl;
    cout << *p_value << endl;
    cout << p_value << endl;
    cout << endl;

    *p_value = 8.94;
    cout << value << endl;
    cout << &value << endl;
    cout << endl;
    cout << ref_value << endl;
    cout << &ref_value << endl;
    cout << *p_value << endl;
    cout << p_value << endl;
    cout << endl;

    ref_value = 12.48;
    cout << value << endl;
    cout << &value << endl;
    cout << endl;
    cout << ref_value << endl;
    cout << &ref_value << endl;
    cout << *p_value << endl;
    cout << p_value << endl;
    cout << endl;

    return 0;

}