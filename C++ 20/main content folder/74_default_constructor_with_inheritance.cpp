#include <iostream>
#include <string>
#include <string_view>
using namespace std;

//Default constructors with inheritance
//Base class constructors are called first before downstream class constructors are called to complete the construction
class Person{
    public:
        Person(){
            cout << "Person default arg constructor called..." << endl;
        }
        ~Person(){}
};

class Engineer: public Person{
    public:
        Engineer(){
            cout << "Engineer default arg constructor called..." << endl;
        }
        ~Engineer(){}
};

class CivilEngineer: public Engineer{
    public:
        CivilEngineer(){
            cout << "Civil Engineer default arg constructor called..." << endl;
        }
        ~CivilEngineer(){}
};

int main(){

    CivilEngineer p1;

    return 0;

}