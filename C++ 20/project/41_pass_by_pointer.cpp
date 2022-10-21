#include <iostream>
#include <string>
using namespace std;

//pass by pointer:
//pass address into function, because address are the same inside or outside function
//value will change even outside the function

void say_age(int *age);

int main(){

    int age {24};
    cout << "before: " << age << " " << &age << endl;
    say_age(&age);
    cout << "after: " << age << " " << &age << endl;

    return 0;

}

void say_age(int *age){
    ++(*age);
    cout << "Hello. You are " << *age << " years old." << " " << age << endl;
}