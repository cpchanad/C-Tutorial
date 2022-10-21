#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
    
    //strcat: concatenate string together
    char dest[50] = "I am very awesome";   // dest array need to be big enough
    char add[15] = " and beatiful.";
    strcat(dest, add);
    strcat(dest, " Thank you very munch.");
    cout << dest << endl;
    cout << endl;

    char *dest1 {new char[50]{'A','B','C','D','E','F','G'}};    //store in heap through 'new'
    const char *add1 {" is the first 7 alphabets in English."}; //store in stack

    cout << strlen(dest1) << endl;
    cout << strlen(add1) << endl;
    cout << endl;

    strcat(dest1, add1);  //return pointer
    cout << dest1 << endl;
    cout << strlen(dest1) << endl;
    cout << endl;

    delete[] dest1;
    dest1 = nullptr;

    //strncat: concatenate n character from add to dest
    char dest2[50] {"Hello"};
    char add2[35] {" World!sfgfshoighroih"};

    strncat(dest2, add2, 7);//return pointer
    cout << dest2 << endl;
    cout << endl;

    //strcpy: copy string from add to dest
    const char *add3 {"C++ is an awesome langauge."};  //doesn't contain null character
    char dest3_DLC[strlen(add3) + 1];                  //Not initialized (optional if add is a pointer:+1 for the null character)
    char *dest3 = new char[strlen(add3) + 1];          //Not initialized (optional if add is a pointer:+1 for the null character)
                                                       //contain garbage data but not a null pointer
    cout << strlen(add3) << endl;
    cout << endl;

    strcpy(dest3, add3);
    strcpy(dest3_DLC, add3);

    cout << sizeof(dest3) << endl;
    cout << strlen(dest3) << endl;
    cout << dest3 << endl;
    cout << sizeof(dest3_DLC) << endl;
    cout << strlen(dest3_DLC) << endl;
    cout << dest3_DLC << endl;
    cout << endl;

    //strncpy: copy n character from add to dest
    const char *add4 {"Hello World!enngdyjnxx"};
    char dest4[] {"123456789012DA"};                //make sure null character at the end

    strncpy(dest4, add4, 12);   //replace '123456789012' with 'Hello World!', 'DA' unaffected
    cout << dest4 << endl;
    cout << endl;

    //extra
    char add5[] {'A','B','C','D','E','F','\0'};//add null character at the end if add is not a pointer
    char dest5[strlen(add5)];                  //Not initialized
    char *dest5_DLC = new char[strlen(add5)];  //Not initialized

    strcpy(dest5, add5);
    strcpy(dest5_DLC, add5);

    cout << dest5 << endl;
    cout << dest5_DLC << endl;

    return 0;

}