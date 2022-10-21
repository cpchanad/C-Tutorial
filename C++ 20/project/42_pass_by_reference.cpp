#include <iostream>
#include <string>
using namespace std;

//pass by reference:
//make a reference of the original one, chaning the value inside the function will affect outside
//because a reference behave like the original one

void say_age(int &age);

int main(){

    int age {24};

    cout << "Before: " << age << " " << &age << endl;
    say_age(age);
    cout << "After: " << age << " " << &age << endl;

    return 0;

}

void say_age(int &age){
    ++age;
    cout << "Hello. You are " << age << " years old. " << &age << endl;
}