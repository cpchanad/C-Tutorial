#include <iostream>
#include <string>
using namespace std;

//Dynamic_cast<>()
//to allow downstream transformation between polymorphic types
//transforming from base class pointer/reference to derived class pointer/reference at run time
//makes it possible to call non-polymorphic method on derived objects (base class pointer)

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
            cout << name << "(feline) with " << fur_style << " color is breathing." << endl;
        }
        //Feline polymorphism
        virtual void run() const{
            cout << name << "(feline) with " << fur_style << " color is running." << endl;
        }
        //Feline method
        void do_something() const{
            cout << name << "(feline) with " << fur_style << " color is doing something." << endl;
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

class BullDog: public Dog{
    public:
        BullDog() = default;
        ~BullDog(){}
        //Animal polymorphism
        void breathe() const override{
            cout << name << "(BullDog) with " << fur_style  << " color is breathing." << endl;
        }
};

void do_something_with_animal_ptr(Animal* animal_ptr);
void do_something_with_animal_ref(Animal& animal_ref);

int main(){

    cout << "static cast:" << endl;
    cout << endl;
    //1.static cast: transform variables with simple type
    double a {12.3};
    int b {};

    cout << b << endl;

    b = static_cast<int>(a);

    cout << b << endl;

    cout << "===============================================" << endl;

    cout << "dynamic cast:" << endl;
    cout << endl;
    //2.dynamic cast: transform class pointer/reference in the same class inheritance
    Animal* animal_ptr = new Dog("dark gray","dog_1");

    Feline feline_obj("stripe","feline_1");
    Animal& animal_ref = feline_obj;

    //a.transform base pointer/reference to the most derived object
    Dog* dog_ptr = dynamic_cast<Dog*>(animal_ptr);                // desired way
    Feline& feline_ref = dynamic_cast<Feline&>(animal_ref);       // not recommened, no way to check for validity
    //base class pointer/reference have no access to dog class function
    //transform to dog object allow non-polymorphic function to be called

    cout << "Using pointer:" << endl;
    //b.pointer
    //before transformation
    if(dog_ptr){                       //check for valid pointer. if dynamic_cast fail, nullptr is returned.
        animal_ptr->breathe();
      //animal_ptr->run();             -> error: no access to feline class function
      //animal_ptr->bark();            -> error: no access to dog class function
      //animal_ptr->do_something();    -> error: no access to feline class function
    }else{
        cout << "dog_ptr not existed." << endl;
    }
    cout << endl;

    //after transformation
    dog_ptr->breathe();
    dog_ptr->run();
    dog_ptr->bark();
    dog_ptr->do_something();
    cout << endl;

    cout << "Using reference:" << endl;
    //c.reference
    //before transformation
    animal_ref.breathe();
  //animal_ref.run();                 -> error: no access to feline class function
  //animal_ref.do_something();        -> error: no access to feline class function
    cout << endl;

    //after transformation
    feline_ref.breathe();
    feline_ref.run();
    feline_ref.do_something();
    cout << endl;
    
    //no nullptr equivalent for reference to check
    Feline* feline_ptr = dynamic_cast<Feline*>(&animal_ref);    //transform from animal_ref_address to feline_ptr
    if(feline_ptr){
        feline_ptr->breathe();
    }else{
        cout << "couldn't cast to Feline reference." << endl;
    }
    cout << "===============================================" << endl;

    cout << "Checking for validiy:" << endl;
    //d.dynamic_cast fail
    BullDog* dog_ptr_1 = dynamic_cast<BullDog*>(animal_ptr);     //animal_ptr are pointing to a Dog object
    if(dog_ptr_1){                                     //cannot transform into derived class object, nullptr returned
        dog_ptr_1->breathe();                              //crash: because no bulldog info on dog object
    }{
        cout << "dog_ptr_1 not existed." << endl;
    }
    cout << endl;

    Dog* dog_ptr_2 = dynamic_cast<Dog*>(&animal_ref);            //animal_ref are referencing a Feline object
    if(dog_ptr_2){                                     //cannot transform into derived class object, nullptr returned
        dog_ptr_2->breathe();                               //crash: because no dog info on feline object
    }else{
        cout << "couldn't cast to dog reference." << endl;
    }
    cout << "===============================================" << endl;

    cout << "Calling function with casting:" << endl;
    //e.casting usually done in function
    do_something_with_animal_ptr(animal_ptr);
    do_something_with_animal_ref(animal_ref);

    //release memory
    delete animal_ptr;

    return 0;

}

void do_something_with_animal_ptr(Animal* animal_ptr){
    cout << "In function taking base pointer..." << endl;
    Dog* dog_ptr = dynamic_cast<Dog*>(animal_ptr);          //casting

    if(dog_ptr){                                            //check for vaildity
        dog_ptr->do_something();
    }else{
        cout << "couldn't cast to dog pointer." << endl;
    }
}

void do_something_with_animal_ref(Animal& animal_ref){
    cout << "In function taking base reference..." << endl;
    Feline* feline_ptr = dynamic_cast<Feline*>(&animal_ref); //casting

    if(feline_ptr){                                          //check for vaildity
        feline_ptr->do_something();
    }else{
        cout << "couldn't cast to feline reference." << endl;
    }
}