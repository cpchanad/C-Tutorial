#include <iostream>
#include <string>
using namespace std;

//Virtual functions with default arguments
//compiler will use static binding to decide which default parameters to pass into the functions
//i.e. compiler will use dynamic binding on function but static binding on default parameters
//better not to use default arguments with virtual function

// default argument are handled at compile time
// virtual functions are called at run time with polymorphism
class Base{
    public:
        Base() = default;
        ~Base(){}

        virtual double add(double a = 5, double b = 5) const{
            cout << "Base::add() called." << endl;
            return (a + b + 1);
        }
};

class Derived: public Base{
    public:
        Derived() = default;
        ~Derived(){}

        virtual double add(double a = 10, double b = 10) const override{
            cout << "Derived::add() called." << endl;
            return (a + b + 2);
        }
};

int main(){

    Base base;
    Derived derived;

    //base pointer
    Base* collection[] {&base, &derived};

    for(const auto& c: collection){
        cout << c->add() << endl;             // 'base' will use base function and base default parameter
    }                                         // i.e. 5 + 5 + 1 = 11
                                              // 'derived' will use derived function and base default parameter
                                              // i.e. 5 + 5 + 2 = 12
    
    cout << endl;

    //base reference
    Base& base_ref = derived;
    int result = base_ref.add();
    cout << result << endl;                   // 5 + 5 + 2 = 12

    cout << endl;

    //direct object: static binding
    Derived derived_2;
    cout << derived_2.add() << endl;          // 10 + 10 + 2 = 22
    
    cout << endl;

    //slicing object: static binding
    Base base_2 = derived_2;
    cout << base_2.add() << endl;              // 5 + 5 + 1 = 11

    return 0;

}