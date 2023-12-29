#include <iostream>
#include <string>
using namespace std;

//returning from functions

//Default is return by value
//It will return a copy store in the outside variable
int sum(int a, int b){
    int result = a + b;
    cout << "In: " << &result << endl;
    return result;
}

//kinda return by reference (not really, just the compiler reuse the address)
//work on string because string usually use up a lot of memory
string add_str(string str1, string str2){
    string result = str1 + str2;
    cout << "In: " << &result << endl;
    return result;
}

int main(){

    int a {34};
    int b {14};
    int result = sum(a,b);
    cout << "Out: " << &result << endl;
    cout << result << endl;
    cout << endl;

    string c {"Hello,"};
    string d {" Long Time no see."};
    string result_str = add_str(c, d);
    cout << "Out: " << &result_str << endl;
    cout << result_str << endl;
 
    return 0;

}