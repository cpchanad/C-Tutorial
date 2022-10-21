#include <iostream>
#include <string>
using namespace std;

//Virtual Destructor
class Animal{
    public:
        Animal(){ cout << "constructor called for Animal: " << name << endl; }
        Animal(string_view m_name)
            :name(m_name){ cout << "constructor called for Animal: " << name << endl; }
        ~Animal(){ cout << "destructor called for Animal: " << name << endl; }          //not adding 'virtual'
                                                                   //Animal* pointer call animal() destructor only
        //Animal polymorphism
        virtual void breathe() const{
            cout << name << "(animal) is breathing." << endl;
        }
    protected:
        string name {"unnamed"};
};

class Feline: public Animal{
    public:
        Feline(){ cout << "constructor called for Feline: " << name << endl; };
        Feline(string_view m_fur_style, string_view m_name)
            :Animal(m_name), fur_style(m_fur_style){ cout << "constructor called for Feline: " << name << endl; }
        virtual ~Feline(){ cout << "destructor called for Feline: " << name << endl; }  //added 'virtual' to let 
                                                                            //Feline* pointer call dog() destructor
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
        Dog(){ cout << "constructor called for Dog: " << name << endl; };
        Dog(string_view m_fur_style, string_view m_name)
            :Feline(m_fur_style,m_name){ cout << "constructor called for Dog: " << name << endl; }
        virtual ~Dog(){ cout << "destructor called for Dog: " << name << endl; }

        //Animal polymorphism
        void breathe() const override{
            cout << name << "(Dog) with " << fur_style  << " color is breathing." << endl;
        }
        //Feline polymorphism
        void run() const override{
            cout << name << "(Dog) with " << fur_style  << " color is running." << endl;
        }
        //Dog method
        virtual void bark() const{
            cout << name << "(Dog) with " << fur_style  << " color is barking." << endl;
        }
    private:
        //no member variables
};

int main(){

    //create Dog object directly
    Dog dog("dark yellow","dog");
    cout << endl;

    //create Animal base pointer with Dog object in heap (no virtual destructor)
    Animal* animal_0 = new Dog("pale blue","animal_0");
    cout << endl;
    //create Feline base pointer with Dog object in heap (virtual destructor)
    Feline* feline_1 = new Dog("great red","feline_1");
    cout << endl;

    //to allow ~Dog() destructor to be called on Animal base pointer when deleting Animal* pointer
    //destructor need to be virtual. otherwise only animal() destructor are called
    //it will execute the most specific destructor if virtual

    //delete Animal base pointer
    delete animal_0;                        // only animal() destructor are called (no virutal)
    cout << endl;                           // dog & feline object memory leaked

    //delete Feline base pointer
    delete feline_1;                        // dog(), feline() & animal() destructor are called (virtual)
    cout << endl;

    return 0;

}