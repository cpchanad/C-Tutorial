#include <iostream>
#include <string>
using namespace std;

//Function signature: Function name + function parameter

//Function take one input, and not return anything explicitly
void enter_bar(int age){
    if(age > 18){
        cout << "You are " << age << " years old. Please procced." << endl;
    }else{
        cout << "Sorry, you are too young for this." << endl;
    }
}

//Function take multiple input, and return result
int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

//Function that doesn't take parameters and returns nothing
void say_hello(){
    cout << "Hello" << endl;
    return;     //can be omitted if function are returning void
}

//Function take no parameter and returns something
int lucky_number(){
    return 99;
}

//Parameter passed into the function are *COPIES* of the arguments 
//Parameter inside the function are scoped locally
double increment_multipy(double i, double j){
    cout << "i & j: " << i << " & " << j << endl;
    double result = (++i) * (++j);
    cout << "After increment," << endl;
    cout << "i & j: " << i << " & " << j << endl;
    return result;
}


int main(){

    enter_bar(29); //Function argument
    cout << max(2,5) << endl;
    say_hello();
    lucky_number();
    cout << endl;

    double a {20.0};
    double b {4};
    cout << "a & b: " << a << " & " << b << endl;
    increment_multipy(a,b);
    cout << "a & b: " << a << " & " << b << endl;

    cout << endl;
    double x {12.2};
    cout << static_cast<int>(x) << endl;    //change from double to int

    return 0;

}