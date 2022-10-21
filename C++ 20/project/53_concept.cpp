#include <iostream>
#include <string>
#include <type_traits>
#include <concepts>
using namespace std;

//Concept
//A mechanism to place constraints on your template type parameters
//1. Standard built in concepts or 2. Custom concept

//The following all do the same thing <integral type>
//syntax 1a. using concept to enforce during declaration
template <typename T>
requires integral<T>    //'requires' keyword & concept & template parameter in angle brackets
T add(T a, T b){        // only accpet parameter that satisfy concept (i.e. only integral type)
    return a + b;
}

//syntax 1b. using type traits
template <typename T>
requires is_integral_v<T>   //check the parameter and evaluate to boolean value, if true concept succeed 
T add_2(T a, T b){            //                                                   if false error
    return a + b;
}

//syntax 2
template <integral T>    //replace typename with concept to enforce
T add_3(T a , T b){
    return a + b;
}

//syntax 3. use auto to setup function template
auto add_4(integral auto a, integral auto b){   //add concept in front of auto keyword to enforce
    return a + b;
}

//syntax 4
template <typename T>
T add_5(T a, T b) requires integral<T>{
    return a + b;
}

//An alternative to static asserts and type traits
template <typename T>
void print_nunmber(T n){
    static_assert(is_integral<T>::value, "Must pass in an intergral argument");
    cout << "n: " << n << endl;
}

int main(){

    char a_0 {10};
    char a_1 {20};
    auto result_a = add(a_0,a_1);
    cout << "result_a: " << static_cast<int>(result_a) << endl;

    int b_0 {11};
    int b_1 {5};
    auto result_b = add_4(b_0,b_1);
    cout << "result_b: " << result_b << endl;

    double c_0 {2.4};             //double are not integral type
    double c_1 {11.4};
  //auto result_c = add(c_0,c_1); //-> error intergral concept not satisfied
    cout << endl;

    int print_test {3};
    print_nunmber(print_test);

    return 0;

}