#include <iostream>
#include <string>
using namespace std;

//template type parameters by value
template <typename T> T maximum(T a, T b);

//Template type parameters by reference
template <typename T> const T &minimum(const T &a, const T &b);

int main(){

    double a {23.5};
    double b {51.2};

    cout << "Out" << endl;

    cout << "address a: " << &a << endl;
    cout << "address b: " << &b << endl;
    cout << endl;

    cout << "In" << endl;

    double max1 = maximum(a,b);
    cout << max1 << endl;

    cout << endl;

    double min1 = minimum(a,b);
    cout << min1 << endl;

    return 0;

}

template <typename T> T maximum(T a, T b){
    cout << "address a: " << &a << endl;
    cout << "address b: " << &b << endl;
    return ( a > b )? a : b;
}

template <typename T> const T &minimum(const T &a, const T &b){
    cout << "address a: " << &a << endl;
    cout << "address b: " << &b << endl;
    return ( a < b )? a : b;
}