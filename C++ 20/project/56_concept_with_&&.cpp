#include <iostream>
#include <string>
#include <concepts>
using namespace std;

//Combine concepts with logical operators && , ||
//need to use 'requires' keyword

//Combining concepts <&&>
template <typename T>
concept Tinytype = requires(T t){
    sizeof(T) <=4;                //simple requirement
    requires sizeof(T) <=4;       //nested requirement
};

template <typename T>
T func_1(T t) requires integral<T> && Tinytype<T>{   //parameter need to be integral type and size less than 4 byte
    cout << "value: " << t << endl;
    return 2*t;
}
//is the same as below
template <typename T>
T func_2(T t) requires integral<T> && requires(T t){  //parameter need to be integral type and size less than 4 byte
    sizeof(T) <=4;
    requires sizeof(T) <=4;
}{
    cout << "value: " << t << endl;
    return 2*t;
}

//Combining concepts <||>
template <typename T>
requires integral<T> || floating_point<T>      //parameter need to be intergral type or floating point type
T func_3(T t){
    cout << "value: " << t << endl;
    return 2*t;
}

int main(){

    int a {12};
    double b {2.4};
    cout << "result: " << func_1(a) << endl;
    cout << "result: " << func_2(a) << endl;
  //cout << "result: " << func_1(b) << endl; // -> error: double are not integral type
  //cout << "result: " << func_2(b) << endl; // -> error: size of double too large
    cout << endl;

    cout << "result: " << func_3(b) << endl;
    //no error because floating point concept allow double
    string c {"Yo"};
  //cout << "result: " << func_3(c) << endl; // -> error: string not integral or floating point type

    return 0;

}