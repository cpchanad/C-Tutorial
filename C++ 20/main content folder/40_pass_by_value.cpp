#include <iostream>
#include <string>
using namespace std;

//pass by value:
//value are passed into the function and it will make a copy of it
//Therefore, will not affect the value outside the function

void say_age(int age);

int main(){

    int age {24};

    cout << "before: " << age << endl;
    say_age(age);
    cout << "after: " << age << endl;

    return 0;

}

void say_age(int age){
    ++age;
    cout << "Hello. You are " << age << " years old." << endl;
}