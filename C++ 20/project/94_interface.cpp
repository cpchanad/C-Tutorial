#include <iostream>
#include <string>
#include <string_view>
#include <memory>
using namespace std;

//Abstract classes as interfaces
//An abstract class with only pure virtual functions and no member variable can be used to model called an interface
//An interface is a specification of something that will be fully implemented in a derived class,
//but the specification itself resides in the abstract class
//Objective: attach interface to the type to give them superpower/new feature
           //save you from having to implement these features separately in each class
//Attach method: inherit from the interface

//interface in C++:
class StreamInsertable{     //have one job -> allow types to insert data into output streams like std::cout streams
    //helper function: declaring stream output operator
    friend ostream& operator<<(ostream& out, const StreamInsertable& operand){   //***base reference 'operand'
        //definition or implementation
        operand.stream_insert(out);       //call stream_insert virtual function on operand
        return out;                       //this will call the most specific implementation for stream_insert
    }                                     //base reference use polymorphism

    //pure virtual function: setup to call virtual function within helper function
    public:
        virtual void stream_insert(ostream& out) const = 0;

    //no member variables
};

//inherit from interface to attach the type
class Point: public StreamInsertable{
    //no need to setup output stream operator
    public:
        Point() = default;
        Point(double m_x, double m_y)
            :x(m_x),y(m_y){}
        
        //override pure virtual function: let inheriting downstream classes to specify what to print
        virtual void stream_insert(ostream& out) const override{
            out << "Point [x: " << x << ",y: " << y << "]";     //specifing what and how to print
        }
    private:
        double x;
        double y;
};

//attach the whole animal class to the interface: give whole Animal class the power to print to output stream
class Animal: public StreamInsertable{
    public:
        Animal() = default;
        Animal(string_view m_name)
            :name(m_name){}
        virtual ~Animal(){}

        //Animal polymorphism
        virtual void breathe() const{
            cout << name << "(animal) is breathing." << endl;
        }

        //Stream insertable interface(override pure virtual function)
        /*
        virtual void stream_insert(ostream& out) const override{
            out << "Animal [name: " << name << " ]";     //specifing what and how to print
        }
        */
        //if not override, it will become an abstract class

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
        virtual void breathe() const override{
            cout << name << "(feline) with " << fur_style << " is breathing." << endl;
        }
        //Feline polymorphism
        virtual void run() const{
            cout << name << "(feline) with " << fur_style << " is running." << endl;
        }

        //Stream insertable interface(override pure virtual function)
        virtual void stream_insert(ostream& out) const override{
            out << "Feline [name: " << name << ",fur style: " << fur_style << " ]";
        }     //specifing what and how to print

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

        //Stream insertable interface(override pure virtual function)
        virtual void stream_insert(ostream& out) const override{
            out << "Dog [name: " << name << ",fur style: " << fur_style << " ]";
        }     //specifing what and how to print
        
    private:
        //no member variables
};

class Cat: public Feline{
    public:
        Cat() = default;
        Cat(string_view m_fur_style, string_view m_name)
            :Feline(m_fur_style,m_name){}
        virtual ~Cat(){}

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

        //Stream insertable interface(override pure virtual function)
        virtual void stream_insert(ostream& out) const override{
            out << "Cat [name: " << name << ",fur style: " << fur_style << " ]";
        }     //specifing what and how to print

    private:
        //no member variables
};

int main(){

    Point pt1(2,4);

    cout << pt1 << endl;    //passing in ostream as base reference(StreamInsertable&)
                            //operand.stream_insert(out) -> pt1.stream_insert(out) get called
                            //use polymorphism           -> go into derived class to specify what and how to print
                            //return out                 ->return out to output stream
    cout << endl;

    //direct
    Dog d1("black stripe","Dog_1");
    Cat c1("Yellow spot","Cat_1");

    cout << d1 << endl;
    cout << c1 << endl;

  //Animal a1;              // -> error: abstract class
    cout << endl;

    //smart pointer
    unique_ptr<Animal> a2 = make_unique<Feline>("stripes", "feline_1");
    cout << *a2 << endl;
    cout << endl;

    //smart pointer array
    shared_ptr<Animal> animals[] {
        make_shared<Dog>("black", "dog_2"),
        make_shared<Cat>("white", "cat_2")
    };
    for(const auto& a: animals){
        cout << *a << endl;
    }

    return 0;

}