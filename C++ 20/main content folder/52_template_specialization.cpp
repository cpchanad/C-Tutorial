#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Function template
template <typename T> T maximum(T a, T b);

//Template specialization
//specialize with specific template for const char pointer
//and only const char pointer can use
template <>
const char* maximum<const char*> (const char* a, const char* b);
//1. force the return type to be const char*
//2. force the argument pass through to be const char*
//3&4. parameter are of const char* type


int main(){

    int a {12};
    int b {36};

    const char* p_message_1 {"This is great."};
    const char* p_message_2 {"This is so bad."};

    cout << maximum(a,b) << endl;  //call normal template
    cout << endl;

    cout << maximum(p_message_1,p_message_2) << endl;   //call specialized template
    //if specialized template not used, it will compare pointer and not what you want

    return 0;

}

template <typename T> T maximum(T a, T b){
    return (a>b)? a : b;
}

template <>
const char* maximum<const char*> (const char* a, const char* b){
    return (strcmp(a,b) > 0)? a : b;
}