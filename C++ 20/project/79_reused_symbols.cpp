#include <iostream>
#include <string>
using namespace std;

//Reused symbols in inheritance
//C++ allow the same function or variable name in base&derived class
//if they have the same name, by default
//Parent class will use parent function & variables (override the other class's function & variables)
//and Child class will use child function & variables (override the other class's function & variables)

class Parent{
    public:
        void print_var(){
            cout << "Parent function called: " << m_var << endl;
        }
    protected:
        int m_var {100};
};

class Child: public Parent{
    public:
        void print_var(){
            cout << "Child function called: " << m_var << endl;
        }
        void show_var(){
            cout << "Child value: " << m_var << endl;
            cout << "Parent value: " << Parent::m_var << endl;   //force to print out parent m_var
        }
    private:
        int m_var {0};
};

int main(){

    cout << "Child: " << endl;

    Child p2;
    p2.print_var();

    //or you can force to call the method in other classes
    p2.Parent::print_var();    // add class name & 2 colon to indicate you want to call other class's function

    cout << endl;

    cout << "Parent: " << endl;

    Parent p1;
    p1.print_var();

    cout << "----------------" << endl;

    p2.show_var();

    return 0;

}