#include <iostream>
#include <string>
#include <string_view>
#include <ios>
#include <iomanip>
using namespace std;

//Destructor
//use to delete things, e.g. release memory
//don't have any parameter list
//no need to directly call destructor e.g. object_name.~class() NONONO

/*
When are destructors called
1. in weird places (not common)
e.g. when an object is passed by value to a function (for somecompilers)
e.g. When a local object is return from a function (for somecompilers)
2. obvious cases
e.g. When a local stack object goes out of scope (dies) -> like  go out of main() or function scope
e.g. When a heap object is released with delete -> manually delete declared pointer object (will not delete automatically)
P.S. remember to delete heap object manually using 'delete object_name'.
*/

class Dog{

    //declaration
    public:
        //constructor header
        Dog();
        Dog(string_view name_param, string_view breed_param, int age_param);   //string_view are read only (faster)

        //destructor header
        ~Dog();

        //method header
        string get_name();
        string get_breed_info();
        int get_age();
        string* get_name_address();
        string* get_breed_info_address();
        int* get_age_address();

        void set_name(string_view name_param);
        void set_breed(string_view breed_param);
        void set_inside_func(string_view TorF);
        void set_age(int age_param);

    private:
        string dog_name;
        string dog_breed;
        bool inside_function;
        int* dog_age {nullptr};      //uninitialized pointer

};

//constructor definition
Dog::Dog(){
    dog_name = "None";
    dog_breed = "None";
    inside_function = false;
    dog_age = new int;      //dynamic memory allocation
    *dog_age = 0;
}
Dog::Dog(string_view name_param, string_view breed_param, int age_param){
    dog_name = name_param;
    dog_breed = breed_param;
    inside_function = false;
    dog_age = new int;      //dynamic memory allocation
    *dog_age = age_param;
    cout << "=====================================" << endl;
    cout << "Dog constructor called for " << dog_name << "." << endl;
    cout << "=====================================" << endl;
}

//destructor definition
Dog::~Dog(){
    if(inside_function == false){
    delete dog_age;                     //release memory on member pointer variable 
    cout << "=====================================" << endl;
    cout << "memroy deleted for " << dog_name << "." << endl;
    }else{
    cout << "=====================================" << endl;
    }
    cout << "Dog destructor called for " << dog_name << "." << endl;
    cout << "=====================================" << endl;
}

//Function take in object & return object
//Passing object by value is bad, because object are copied and when get out of function, copy are deleted (pointer fail)
Dog fertile_operation(Dog patient){                  //'dog_1' object are copied to 'patient', step:
    patient.set_inside_func("Y");                    //1. copy the Dog class member variables
    if(patient.get_breed_info() == "Infertile"){     //2. copy 'dog_1' object variables' data to patient
        cout << "Patient Info" << endl;              //P.S. normal->data are copied, but pointer->the address are copied
        cout << left;
        cout << setw(15) << "Name:" << setw(10) << patient.get_name() 
            << "(" << patient.get_name_address() << ")" << endl;
        cout << setw(15) << "Breed Info:" << setw(10) << patient.get_breed_info() 
            << "(" << patient.get_breed_info_address() << ")" << endl;
        cout << setw(15) << "Age: " << setw(10) << patient.get_age() 
            << "(" << patient.get_age_address() << ")  stored in heap" << endl;
        patient.set_name(patient.get_name() + " (AO)");
        patient.set_breed("Fertile");
        cout << "Operation succeed." << endl;
        return patient;                              //'patient' object die when function are over
    }else{                                           // because patient only exist inside the function scope
        cout << "Not suitable for operation." << endl;
        return patient;
    }   
}

//delete heap object manually
void test(){
    Dog* dog_test = new Dog("Test","Test",1);
    delete dog_test;                           //cause destructor of dog to be called
}

int main(){

    Dog dog_1("Alex","Infertile",5);

    cout << "Dog Info" << endl;
    cout << left;
    cout << setw(15) << "Name:" << setw(10) << dog_1.get_name() 
        << "(" << dog_1.get_name_address() << ")" << endl;
    cout << setw(15) << "Breed Info:" << setw(10) << dog_1.get_breed_info() 
        << "(" << dog_1.get_breed_info_address() << ")" << endl;
    cout << setw(15) << "Age: " << setw(10) << dog_1.get_age() 
        << "(" << dog_1.get_age_address() << ")  stored in heap" << endl;
    cout << endl;

    cout << "Alex is applied for fertile operation." << endl;
    cout << endl;
    cout << "Operation now in progress..." << endl;
    Dog dog_1_rev1 = fertile_operation(dog_1);
    dog_1_rev1.set_inside_func("N");

    cout << "Dog Info" << endl;
    cout << left;
    cout << setw(15) << "Name:" << setw(10) << dog_1_rev1.get_name() 
        << "(" << dog_1_rev1.get_name_address() << ")" << endl;
    cout << setw(15) << "Breed Info:" << setw(10) << dog_1_rev1.get_breed_info() 
        << "(" << dog_1_rev1.get_breed_info_address() << ")" << endl;
    cout << setw(15) << "Age: " << setw(10) << dog_1_rev1.get_age() 
        << "(" << dog_1_rev1.get_age_address() << ")  stored in heap" << endl;
    cout << endl;

    test();

    cout << "Program ended." << endl;

    return 0;

}

//method definition
string Dog::get_name(){
    return dog_name;
}

string Dog::get_breed_info(){
    return dog_breed;
}

int Dog::get_age(){
    return *dog_age;
}

string* Dog::get_name_address(){
    return &dog_name;
}

string* Dog::get_breed_info_address(){
    return &dog_breed;
}

int* Dog::get_age_address(){
    return dog_age;
}


void Dog::set_name(string_view name_param){
    dog_name = name_param;
}

void Dog::set_breed(string_view breed_param){
    dog_breed = breed_param;
}

void Dog::set_inside_func(string_view TorF){
    if(TorF == "Y"){
        inside_function = true;
    }else{
        inside_function = false;
    }
}

void Dog::set_age(int age_param){
    *dog_age = age_param;
}