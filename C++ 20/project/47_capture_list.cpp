#include <iostream>
#include <string>
using namespace std;

int main(){

    //capture list in lambda function
    //give you access to things outside the scope of the lambda function
    double a {20.3};
    double b {3.3};

    auto multiply = [a,b](){                   //capture a & b variable and use it inside the function
        cout << "a * b = " << a * b << endl;
    };
    multiply();
    cout << endl;

    //capturing by value: make a copy of the original can capture it in lambda function
    //Outside change will not affect inside the lambda function
    int c {42};

    auto func = [c](){                                        //lambda function capture the variable & make a copy
        cout << "In: " << c << " ( " << &c << " )" << endl;   //its going to capture 42
    };

    for(size_t i {}; i < 5; ++i){
        cout << "Out: " << c << " ( " << &c << " )" << endl;  //Increscing outside will not affect the copy inside the lambda function
        func();                                               //because it copy c=42 when it declare
        ++c;
    }
    cout << endl;

    //capturing by reference: working on the original outside value
    //Outside change will affect inside the lambda function
    int d {55};

    auto func2 = [&d](){
        cout << "In: " << d << " ( " << &d << " )" << endl;
    };

    for(size_t i {}; i < 5; ++i){
        cout << "Out: " << d << " ( " << &d << " )" << endl;
        func2();
        ++d;
    }
    cout << endl;

    return 0;

}