#include <iostream>
#include <string>
using namespace std;

//Function overloading
//A mechanism in C++ to have mulitple copies of the same function that taking different parameter

int max(int a, int b);                          //if we pass a argument with int, compiler will call the int function
double max(double a, double b);                 //if double is passed into the function, call double
string_view max(string_view a, string_view b);  //if string pass into, choose string
double max(int a, double b);            //different type of parameter
double max(double a, int b);            //parameter with different order
double max(double a, int b, int c);     //different number of parameter 

//overload rule:
//1. different function need to have the same name
//2. different function need to take different type of parameter
//3. overload need separation of declaration & definition of function

//parameter differences
//change the 1. Order , 2. Number , 3. Types of the parameter
//The return type are not enough to make the differences

int main(){

    int a {35};
    int b {87};

    double c {23.92};
    double d {12.29};

    string_view e {"Eat"};
    string_view f {"Doggie"};

    cout << max(a,b) << endl;
    cout << max(c,d) << endl;
    cout << max(e,f) << endl;
    cout << max(a,c) << endl;
    cout << max(d,b) << endl;
    cout << max(c,a,b) << endl;

    return 0;

}

int max(int a, int b){
    cout << "int overload called." << endl;
    return (a>b)? a : b;
}

double max(double a, double b){                  //different type of parameter
    cout << "double overload called." << endl;
    return (a>b)? a : b;
}

string_view max(string_view a, string_view b){   //different type of parameter
    cout << "string overload called." << endl;
    return (a>b)? a : b;                         
}

double max(int a, double b){                     //different type of parameter
    cout << "int/double overload called." << endl;
    return (a>b)? a : b;
}

double max(double a, int b){                     //parameter with different order
    cout << "double/int overload called." << endl;
    return (a>b)? a : b;
}

double max(double a, int b, int c){              //different number of parameter 
    cout << "double/int/int overload called." << endl;
    if(a>b){
        return (a>c)? a : c;
    }else{
        return (b>c)? b : c;
    }
}