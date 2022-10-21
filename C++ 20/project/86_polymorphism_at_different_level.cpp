#include <iostream>
#include <string>
#include <string_view>
using namespace std;

//inheritance and polymorphism at different level

class Animal{
    public:
        Animal() = default;
        Animal(string_view m_name)
            :name(m_name){}
        virtual ~Animal(){}          //should make the destructor virtual if you use virtual functions

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
        virtual ~Feline(){}          //should make the destructor virtual if you use virtual functions

        //Animal polymorphism
        virtual void breathe() const override{
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
        virtual ~Dog(){}          //should make the destructor virtual if you use virtual functions

        //Animal polymorphism
        virtual void breathe() const override{
            cout << name << "(Dog) with " << fur_style  << " color is breathing." << endl;
        }
        //Feline polymorphism
        virtual void run() const override{
            cout << name << "(Dog) with " << fur_style  << " color is running." << endl;
        }
        //Dog method
        virtual void bark() const{
            cout << name << "(Dog) with " << fur_style  << " color is barking." << endl;
        }
    private:
        //no member variables
};

class Cat: public Feline{
    public:
        Cat() = default;
        Cat(string_view m_fur_style, string_view m_name)
            :Feline(m_fur_style,m_name){}
        virtual ~Cat(){}          //should make the destructor virtual if you use virtual functions

        //Animal polymorphism
        virtual void breathe() const override{
            cout << name << "(Cat) with " << fur_style  << " color is breathing." << endl;
        }
        //Feline polymorphism
        virtual void run() const override{
            cout << name << "(Cat) with " << fur_style  << " color is running." << endl;
        }
        //Cat method
        virtual void miaw() const{
            cout << name << "(Cat) with " << fur_style  << " color is miawing." << endl;
        }
    private:
        //no member variables
};

class Bird: public Animal{
    public:
        Bird() = default;
        Bird(string_view m_wing_color, string_view m_name)
            :Animal(m_name), wing_color(m_wing_color){}
        virtual ~Bird(){}          //should make the destructor virtual if you use virtual functions

        //Animal polymorphism
        virtual void breathe() const override{
            cout << name << "(bird) with " << wing_color << " is breathing." << endl;
        }
        //Bird polymorphism
        virtual void fly() const{
            cout << name << "(bird) with " << wing_color << " is flying." << endl;
        }
    protected:
        string wing_color {"no"};
};

class Pigeon: public Bird{
    public:
        Pigeon() = default;
        Pigeon(string_view m_wing_color, string_view m_name)
            :Bird(m_wing_color,m_name){}
        virtual ~Pigeon(){}          //should make the destructor virtual if you use virtual functions

        //Animal polymorphism
        virtual void breathe() const override{
            cout << name << "(Pigeon) with " << wing_color  << " color is breathing." << endl;
        }
        //Bird polymorphism
        virtual void fly() const override{
            cout << name << "(Pigeon) with " << wing_color  << " color is flying." << endl;
        }
        //Pigeon method
        virtual void coo() const{
            cout << name << "(Pigeon) with " << wing_color  << " color is cooing." << endl;
        }
    private:
        //no member variables
};

class Crow: public Bird{
    public:
        Crow() = default;
        Crow(string_view m_wing_color, string_view m_name)
            :Bird(m_wing_color,m_name){}
        virtual ~Crow(){}          //should make the destructor virtual if you use virtual functions

        //Animal polymorphism
        virtual void breathe() const override{
            cout << name << "(Crow) with " << wing_color  << " color is breathing." << endl;
        }
        //Bird polymorphism
        virtual void fly() const override{
            cout << name << "(Crow) with " << wing_color  << " color is flying." << endl;
        }
        //Crow method
        virtual void caw() const{
            cout << name << "(Crow) with " << wing_color  << " color is cawing." << endl;
        }
    private:
        //no member variables
};

int main(){

    //declare animal objects
    Dog d1("dark gray","dog_1");
    Cat c1("black stripes","cat_1");
    Pigeon p1("white","pigeon_1");
    Crow w1("black","crow_1");

    //putting base pointers to animal objects in an array
    Animal* animal_collection[] {&d1,&c1,&p1,&w1};

    cout << "Animal polymorphism" << endl;
    for(const auto& animal: animal_collection){
        animal->breathe();
    }
    cout << endl;

    //putting base pointers to animal objects in an array
    Feline* feline_collection[] {&d1,&c1};              // Animal* pointer won't work because it has no run() method
  //Feline* feline_collection_2[] {&d1,&c1,&p1,&w1};     -> error: pigeon(p1) & crow (w1) is not a feline

    cout << "Feline polymorphism" << endl;
    for(const auto& feline: feline_collection){
        feline->run();
    }
    cout << endl;

    //putting base pointers to animal objects in an array
    Bird* bird_collection[] {&p1,&w1};                  // Animal* pointer won't work because it has no fly() method
  //Bird* bird_collection_2[] {&d1,&c1,&p1,&w1};     -> error: dog(d1) & cat(c1) is not a bird

    cout << "Bird polymorphism" << endl;
    for(const auto& bird: bird_collection){
        bird->fly();
    }
    cout << endl;

    //their own method
    cout << "Own method" << endl;
    d1.bark();
    c1.miaw();             // can't use any base pointer
    p1.coo();              // to excute their own method
    w1.caw();

    return 0;

}