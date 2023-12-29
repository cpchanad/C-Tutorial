#include <iostream>
#include <string>
#include <concepts>
using namespace std;

//Custom concept

//Different way to build concepts
//One line concept
template <typename T>
concept MyIntegral = is_integral_v<T>;

//Multiple line concept
template <typename T>
concept Multipliable = requires(T a, T b){
    a * b;                                      //put in syntax you want your concept to satisfy
};             //add semi-colon at the end
//For example, it require the 2 variables a&b support the mulitiplication operator
//if not supported concept -> failed

template <typename T>
concept Incrementable = requires (T a){
    a+=1;
    ++a;                                        //put in syntax you want your concept to satisfy
    a++;
};             //add semi-colon at the end
//all 3 syntax must be satisfied in order for concept to succeed

//====================================================================================================

//Using custom concept
template <typename T>
requires MyIntegral<T>         //insert custom concept like standard concept
T add_1(T a, T b){
    return a + b;
}

template <Multipliable T>
T mul_1(T a, T b){
    return a * b;
}

auto add_2(Incrementable auto a, Incrementable auto b){
    return a + b + 1;
}

int main(){

    int a {14};
    int b {16};
    cout << add_1(a,b) << endl;
    cout << endl;

    string c {"This"};
    string d {"You"};
    double e {3};
    double f {4};
    cout << mul_1(e,f) << endl;
 // cout << mul_1(c,d) << endl; //error -> string cannot be multiplied
    cout << endl;

    cout << add_2(a,b) << endl;
 // cout << add_2(c,d) << endl; //error -> string cannot be a++ or ++a

    return 0;

}