#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){

    //C-string manipulation
    //include standard library cstring

    //char array
    const char message[] {"Hello World? This is not me."};
    //array decays into pointer
    const char *p_message {"Hello World! This is all you."};   // ***I don't think char pointer contain null character

    //strlen: get the length of a C-string (ignore null character i.e. '\0')
    cout << message << endl;
    cout << strlen(message) << endl;// get the length of a C-string (ignore null character i.e. '\0')
    cout << size(message) << endl;// get the size of the array (include null character)
    cout << sizeof(message) << endl;// get the size of the array (include null character)
    cout << endl;

    cout << p_message << endl;
    cout << strlen(p_message) << endl;// get the length of a C-string (work on decays pointer too)
    //cout << size(p_message) << endl;  -> error no size allow
    cout << sizeof(p_message) << endl;// get the size of the pointer
    cout << endl;

    //strcmp(*lhs,*rhs): compare string until char are different (use to check whether the string are equal)
    //lhs = left hand side, rhs = right hand side
    //return value: int
    //-ve:  if lhs appear before rhs
    //zero: if lhs appear the same as rhs
    //+ve:  if lhs appear after rhs
    const char *str_data_1 {"Alabama"};
    const char *str_data_2 {"Alacama"};
    cout << "'strcmp' compare result:" << endl;
    cout << strcmp(str_data_1,str_data_2) << endl;

    //strncmp(*lhs,*rhs,count): compare n characters in strings until char are different or n char are all the same
    //(use to check whether the string are equal)
    size_t n {3};
    const char *str_data_3 {"aaace"};
    const char *str_data_4 {"aaaibk"};
    cout << "'strncmp' compare result:" << endl;
    cout << strncmp(str_data_3,str_data_4,n) << endl;
    cout << endl;

    //strchr: find the first occurrence of a character
    //return value: if found return pointer, otherwise null pointer
    const char *str {"Yo. This is a disaster. So what are you gonna do?"};
    char target = 'S';
    const char *result = str; // assigning the str pointer into result (not address)
    int iter {};

    cout << result[12] << endl;    //get the 12th position char
    cout << *(result + 12) << endl;//get the 12th position char
    cout << endl;

    result = strchr(result, target);  //return pointer (a string "So what ...") if 'S' is found
    if(result == nullptr){            //return nullptr if 'b' is not found
        cout << "nullptr!" << endl;
    }else{
        cout << "found something" << endl;
    }
    cout << endl;

    result = str;
    while(strchr(result, target) != nullptr){
        ++result;   //result = result + 1 which mean pointer move to the right and assign that pointer into result
        ++iter;
    }
    cout << "iteration :" << iter << endl;  // 'S' occur in 24th postion, 25 if counting from 1
    cout << endl;

    //strrchr: find the last occurenece of a character
    //return value: if found return pointer, otherwise null pointer
    result = "D:\\Permanent Files\\Coding Test\\C++ 20\\project\\test.ccp";
    const char *output = strrchr(result, '\\');
    if(output){
        cout << output + 1 << endl;
    }else{
        cout << "nothing found" << endl;
    }

    return 0;

}