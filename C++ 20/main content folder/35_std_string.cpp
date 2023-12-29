#include <iostream>
#include <string>
using namespace std;

int main(){

    //std::string
    string full_name;                       //Empty string
    string planet {"Earth"};                //Initialize with string literal
    string message_0 {planet};              //Initialize with existing string
    string message_1 {"Hello There",5};     //Initialize with part of the string literal, taking the first 5 character
    string message_2 (4,'a');               //Initialize with a char 4 times (*not curly bracket)
    string message_3 {"Hello world"};       
    string saying_hello {message_3, 6, 5};  //Initialize with part of the existing string,
                                            //starting at index 6 & taking 5 character

    cout << full_name << endl;
    cout << planet << endl;
    cout << message_0 << endl;
    cout << message_1 << endl;
    cout << message_2 << endl;
    cout << message_3 << endl;
    cout << saying_hello << endl;
    cout << endl;

    planet = "Mars. The terrain are not even.";                     //changing string will return the "Earth" memory back to OS
    cout << planet << endl;

    const char *p_planet {"Earth. The sky is blue and beatiful."};  //store in raw array
    p_planet = "Jupiter. The cloud are thick and metallic.";        //changing will point to another address,
    cout << p_planet << endl;                                       //the "Earth" memory will be wasted and return not back to OS
    return 0;

}