#include <iostream>
#include <string>
using namespace std;

//final specifier in inheritance
//1. restrict how you override methods in derived classes
//2. restrict how you can derive from a base class

class Animal{
    public:
        Animal() = default;
        Animal(string_view m_name)
            :name(m_name){}
        virtual ~Animal(){}

        //Animal polymorphism
        virtual void breathe() const{
            cout << name << "(animal) is breathing." << endl;
        }
    protected:
        string name {"unnamed"};
};

class Feline: public Animal{
    public:
        Feline() = default;
        Feline(string_view m_fur_style, string_view m_name)
            :Animal(m_name), fur_style(m_fur_style){}
        virtual ~Feline(){}

        //Animal polymorphism
        void breathe() const override{
            cout << name << "(feline) with " << fur_style << " is breathing." << endl;
        }
        //Feline polymorphism
        virtual void run() const{
            cout << name << "(feline) with " << fur_style << " is running." << endl;
        }
    protected:
        string fur_style {"no"};
};

class Dog: public Feline{
    public:
        Dog() = default;
        Dog(string_view m_fur_style, string_view m_name)
            :Feline(m_fur_style,m_name){}
        virtual ~Dog(){}

        //Animal polymorphism
        void breathe() const override{
            cout << name << "(Dog) with " << fur_style  << " color is breathing." << endl;
        }
        //Feline polymorphism
        //'final' keyword: no downstream class are able to override the run method further
        // better not to add 'virtual' because 'final' & 'virtual' contradict each other
        void run() const override final{                                              // added 'final'
            cout << name << "(Dog) with " << fur_style  << " color is running." << endl;
        }
        //Dog method
        virtual void bark() const{
            cout << name << "(Dog) with " << fur_style  << " color is barking." << endl;
        }
    private:
        //no member variables
};

class BullDog: public Dog{
    public:
        BullDog() = default;
        BullDog(string_view m_fur_style, string_view m_name)
            :Dog(m_fur_style,m_name){}
        ~BullDog(){}

        //Animal polymorphism
        void breathe() const override{
            cout << name << "(BullDog) with " << fur_style  << " color is breathing." << endl;
        }
        //Feline polymorphism
        /*
        virtual void run() const override{                                              -> error: not able to override
            cout << name << "(BullDog) with " << fur_style  << " color is running." << endl;      because of 'final'
        }                                  // cannot override final methods
        */
        //Dog polymorphism
        void bark() const override{
            cout << name << "(BullDog) with " << fur_style  << " color is barking." << endl;
        }
    private:
        //no member variables
};

class Cat final: public Feline{                                                              // added 'final'
//'final' keyword: restrict further sub-classing downstream
    public:
        Cat() = default;
        Cat(string_view m_fur_style, string_view m_name)
            :Feline(m_fur_style,m_name){}
        virtual ~Cat(){}

        //Animal polymorphism
        void breathe() const override{
            cout << name << "(Cat) with " << fur_style  << " color is breathing." << endl;
        }
        //Feline polymorphism
        void run() const override{
            cout << name << "(Cat) with " << fur_style  << " color is running." << endl;
        }
        //Cat method
        //useless virtual method. 'Cat' is final, no one will be deriving from this class
        virtual void miaw() const{                                                    // no need to add 'virtual'
            cout << name << "(Cat) with " << fur_style  << " color is miawing." << endl;
        }
    private:
        //no member variables
};

/*
class WildCat: public Cat{
                                                   -> error: because 'Cat' class is final base class
};                                                           further dervied class from 'Cat' is not allowed
*/

int main(){

    BullDog bd1("Pale Black","BullDog_1");

    bd1.bark();    // BullDog function are called (overrided) 
    bd1.run();     // Dog function are called (not overrided)

    return 0;

}