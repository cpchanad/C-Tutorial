#include <iostream>
#include <string>
using namespace std;

//virtual functions in constructor & destructor
//Don't call virtual functions from inside constructor and destructor
class Base{
    public:
        Base(){
            cout << "Base constructor called." << endl;
            if(x){
                this->setup();                                   //don't set virtual function inside constructor
            }
        }
        virtual ~Base(){
            if(x){
                this->clean_up();                                //don't set virtual function inside destructor
            }
            cout << "Base destructor called." << endl;
            cout << endl;
            cout << "m_value: " << m_value << endl;
        }

        virtual void setup(){
            cout << "Base::setup() called." << endl;
            m_value = 10;
        }
        virtual void clean_up(){
            cout << "Base::clean_up() called." << endl;
            m_value = -10;
        }
        int get_value(){
            return m_value;
        }
        static int x;
    protected:
        int m_value;
};

int Base::x {1};

class Derived: public Base{
    public:
        Derived()
            :Base(){
                cout << "Derived constructor called." << endl;
            }
        virtual ~Derived(){
            cout << "Derived destructor called." << endl;
        }

        virtual void setup() override{
            cout << "Derived::setup() called." << endl;
            m_value = 100;
        }
        virtual void clean_up() override{
            cout << "Derived::clean_up() called." << endl;
            m_value = -100;
        }
};

int main(){

    cout << "Example:" << endl;
    //setup base pointer on derived object
    Base* b = new Derived;

    /*Constuctor and destructor call order:
      Base Constructor    -> call virtual function, but derived class not yet setup -> call base class function (static binding)
      Derived Constructor
            //use constructed object
      Derived Destructor
      Base Destructor     -> call virtual function, but derived class not destroyed -> call base class function (static binding)
    */
    //Result:
    //Calling a virtual function from constructor or destructor won't give polymorphic results
    //i.e. only base class virtual function are called (get static binding result)

    cout << endl;
    cout << "m_value: " << b->get_value() << endl;       // 10
    cout << endl;

    //release memory
    delete b;

    cout << "===========================================" << endl;
    Base::x = 0;
    //Fix: call virtual function on fully constructed object (get dynamic binding)
    Base* b_2 = new Derived;
    b_2->setup();                                        //call setup() right after object created

    cout << endl;
    cout << "m_value: " << b_2->get_value() << endl;     // 100
    cout << endl;

    b_2->clean_up();                                     //call clean_up() right before object get deleted
    delete b_2;

    return 0;

} 