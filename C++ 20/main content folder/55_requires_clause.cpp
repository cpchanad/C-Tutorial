#include <iostream>
#include <string>
#include <concepts>
using namespace std;

//requires clause
//1. simple requirements
//2. nested requirements
//3. compound requirements
//4. type requirements

//1. simple requirments
//Only checks for valid syntax
template <typename T>
concept TinyType_1 = requires(T t){
    sizeof(T) <=4;                 //not checking type of variable need to be less than 4 byte
};                                 //only check syntax

template <typename T>
requires TinyType_1<T>
T test_1(T a, T b){
    return ( a > b )? a : b;
}
//2. nested requirements
//check if the expression is true
template <typename T>
concept TinyType_2 = requires(T t){
    sizeof(T) <=4;                 //simple requirements: check syntax
    requires sizeof(T) <=4;        //nested requirements: check if the expression is true
};                                 //checking type of variable need to be less than 4 byte

template <typename T>
requires TinyType_2<T>
T test_2(T a, T b){
    return ( a > b)? a : b;
}

//3. compound requirements
//put syntax in curly bracket and enforce the value in the bracket to be something
template <typename T>
concept Addable = requires(T a, T b){
    {a + b} noexcept -> convertible_to<int>;  //check if a + b is valid syntax
};  //doesn't throw expections(optional)
    //result is convertible to int (optional)

template <Addable T>
T test_3(T a, T b){
    return a + b;
}

template <typename T>
concept Addable_2 = requires(T a, T b){
    {a + b};  //check if a + b is valid syntax
};
Addable_2 auto test_4(Addable_2 auto a, Addable_2 auto b){
    return a + b;
}

int main(){

    //simple requirements: working
    long double a {3.3L};
    long double b {4.9L};
    cout << sizeof(a) << endl;
    cout << test_1(a,b) << endl;
    cout << endl;

    //nested requirement: not working
    int c {4};
    int d {15};
    cout << sizeof(c) << endl;
    cout << test_1(c,d) << endl;
  //cout << test_2(a,b) << endl; // -> error because sizeof long double is larger than 4
    cout << endl;

    //compound requirement
    char e {12};
    char f {23};
    cout << test_3(a,b) << endl;
    cout << test_3(c,d) << endl;
    auto result = test_3(e,f);
    cout << result << endl;
    cout << static_cast<int>(result) << endl;
    cout << sizeof(result) << endl;
    cout << endl;
    
    string g {"Hello"};
    string h {"World"};
  //cout << test_3(g,h) << endl; // -> error: string cannot be convert to int
    cout << test_4(g,h) << endl; // string is addable by another string

    return 0;

}

