#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){

    //strchr: return pointer
    const char *str {"Try not. Do, or do not. There is no try."};
    char target = 'o';
    const char *result = str;
    size_t iterations {};
    
    cout << strchr(result, target) << endl;  //return a pointer (i.e. a c-string starting with the target charachter)
    cout << endl;

    while((result = strchr(result, target)) != nullptr){
        cout << "Found '" << target << "' starting at '" << result << "'" << endl;
        ++result;
        ++iterations;
    }
    cout << "iterations: " << iterations << endl;

    return 0;

}