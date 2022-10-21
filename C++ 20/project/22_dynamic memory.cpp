#include <iostream>
#include <string>
using namespace std;

int main(){

    //memory map: virtual memory -> actual physical memory
    //stack: store local variables, function...
    //heap: additional memory that can be queried for at run time (if stack memory not enough)
    //heap -> dynamic memory

    //stack: not in full control (lifetime unknown)
    {
        int number {33}; //variable only exist within the {} scope (not outside)
        cout << number << endl;
    }
    cout << endl;

    //heap: in full control (can control through new and delete operators)
    int *p_number {nullptr};
    p_number = new int;       //allocate dynamic memory through 'new' (give you dynamic memory with size of 4 bytes)

    *p_number = 88;           //writting into dynamically allocated meory
    //stored in heap
    cout << *p_number << endl;
    cout << p_number << endl;
    cout << endl;

    //initialize with 'new' upon pointer declaration
    int *a_b {new int};
    int *a_c {new int (36)};  //direct initialization
    int *a_d {new int {48}};  //uniform initializtion

    cout << *a_b <<endl;  //junk value
    cout << *a_c <<endl;
    cout << *a_d <<endl;
    
    //reset and release
    delete p_number;     //releasing: return memory to the OS, p_number contain junk address
    p_number = nullptr;  //resetting: to indicate no vaild data in that *p_number

    //delete p_a;
    //p_a = nullptr;

    delete a_b;
    a_b = nullptr;
    delete a_c;
    a_c = nullptr;
    delete a_d;
    a_d = nullptr;

    //reuse pointer
    string *p_test {new string {"Hello"}};
    cout << p_test << endl;
    cout << *p_test << endl;
    delete p_test;
    p_test = new string {"World"};
    cout << p_test << endl;
    cout << *p_test << endl;
    delete p_test;
    p_test = nullptr;
    cout << p_test << endl;

    return 0;

}