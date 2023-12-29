#include <iostream>
#include <string>
using namespace std;

//Template type deduction and explicit argument

template <typename T> T maximum(T a, T b);
                    //these are template parameter
int main(){

    int a {2};
    int b {5};

    double c {32.9};
    double d {23.5};

    string e {"Hello"};
    string f {"World"};

    //Template type deduction
    maximum(a,b);  //int type deduced
    maximum(c,d);  //double type deduced
    maximum(e,f);  //string type deduced

    //explicit template argument
    maximum<double>(c,d);     //explicitly say the arguments we want double
          //these are template argument

    maximum<double>(a,c);     //implicit conversion ('a' varibale) from int to double

    //maximum<double>(a,e);   //error -> can't convert string to double

    return 0;

}

template <typename T> T max(T a, T b){
    return (a > b)? a : b;
}