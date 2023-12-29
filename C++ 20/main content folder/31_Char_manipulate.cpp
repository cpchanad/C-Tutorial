#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main(){
    
    //Character manipulation
    //Standard library header <cctype>

    //All function only work on one char, use loop to check a char in string one by one

    //1.Check if character is alphanumeric
    char input {82};
    if(isalnum(input)){
        cout << input << " is alphanumeric." << endl;
    }else{
        cout << input << " is not alphanumeric." << endl;
    }
    cout << boolalpha;

    //2.Check if character is alphabetic
    cout << bool(isalpha(input)) << endl;

    //3.Check if a character is blank
    char c_array[] {"Hello World. This your assignment here."};
    int no_blank {};
    cout << c_array << endl;
    for(auto i: c_array){
        if(isblank(i)){
            no_blank++;
        }
    }
    cout << "No of blank in the sentence is " << no_blank << "." << endl;

    //4.Check if character is lowercase or uppercase
    cout << bool(isupper(input)) << endl;
    cout << bool(islower(input)) << endl;

    //5.Check if character is a digit
    cout << bool(isdigit(input)) << endl;
    
    //6.Turning a character to lowercase/uppercase
    char c_array_2[] {"The age of Empire: Revolution of the universe"};
    char dest_array[size(c_array_2)];
    for(size_t i {}; i < size(c_array_2); i++){
        dest_array[i] = toupper(c_array_2[i]);
    }
    cout << dest_array << endl;
    for(size_t i {}; i < size(c_array_2); i++){
        dest_array[i] = tolower(c_array_2[i]);
    }
    cout << dest_array << endl;

    return 0;

}