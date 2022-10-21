#include <iostream>
#include <string>
#include <string_view>
using namespace std;

//The 'this' pointer inside the class function
//Each class member function contains a hidden pointer called this.
//That pointer contains the address of the current object, for which the method is being executed.
//This also applies to constructors and destructors.

//A special pointer maintained by the c++ system that pointing to the current object
//manipulated by special function of the class object that is being called
class Dog{

    //declaration
    public:
        //constructor header
        Dog();
        Dog(string_view name_param, string_view breed_param, int age_param);   //string_view are read only (faster)

        //destructor header
        ~Dog();

        //methods header
        //pointer version
        Dog* set_name(const string& dog_name);     //need 'const' because str are passing in as 'const char'
        Dog* set_dog_breed(const string& breed);   //and it is a reference too, they need to be the same
        Dog* set_dog_age(int age);
        //reference version
        Dog& set_name_r(const string& dog_name);    //return type is 'Dog' object reference
        Dog& set_dog_breed_r(const string& breed);  //i.e. object inside function and outside are the same
        Dog& set_dog_age_r(int age);

        void print_info();

    private:
        string dog_name;
        string dog_breed;
        int* dog_age {nullptr};

};

//Use One.
//indicate current object address
Dog::Dog(){
    dog_name = "None";
    dog_breed = "None";
    dog_age = new int;      //dynamic memory allocation
    *dog_age = 0;
    cout << "Dog: " << dog_name << " constructed at " << this << endl;
}
Dog::Dog(string_view name_param, string_view breed_param, int age_param){
    dog_name = name_param;
    dog_breed = breed_param;
    dog_age = new int;      //dynamic memory allocation
    *dog_age = age_param;
    cout << "Dog: " << dog_name << " constructed at " << this << endl;
}
Dog::~Dog(){
    delete dog_age;                     //release memory on member pointer variable 
    cout << "Dog: " << dog_name << " destructed at " << this << endl;
}

//Use Two.
//clear member variable with function parameter
Dog* Dog::set_name(const string& dog_name){   //function parameter have the same name as the class member variable
  //dog_name = dog_name;      // -> error    //compiler confuse which dog_name you are referring to
    this->dog_name = dog_name;               //use 'this->dog_name' to indicate member variable
    return this;                             //assign 'dog_name' function parameter to member variable
}
Dog& Dog::set_name_r(const string& dog_name){
  //dog_name = dog_name;      // -> error
    this->dog_name = dog_name;
    return *this;         
}

//Use Three.
//Chained calls with pointers
Dog* Dog::set_dog_breed(const string& breed){
    this->dog_breed = breed;
    return this;                //return address for use in chained calls
}
Dog* Dog::set_dog_age(int age){
    if(this->dog_age){           //check for nullptr
        *(this->dog_age) = age;
    }
    return this;
}
//Chained calls with reference
Dog& Dog::set_dog_breed_r(const string& breed){
    this->dog_breed = breed;
    return *this;                //Dereference 'this' address and return object
}
Dog& Dog::set_dog_age_r(int age){
    if(this->dog_age){           //check for nullptr
        *(this->dog_age) = age;
    }
    return *this;
}

int main(){
    
    //Use One.
    //indicate address
    Dog dog1;
    Dog dog2("VeryVeryVeryLongName","Fertile",2);

    cout << endl;
    cout << "Dog1: " << &dog1 << endl;   //&dog1 = this
    cout << "Dog2: " << &dog2 << endl;   //&dog2 = this
    cout << endl;

    //========================================================
    Dog* p_dog1 = new Dog("Alex","Fertile",5);
    p_dog1->print_info();

    cout << endl;
    
    //Use three.
    //chained call executed
    //pointer version (use -> because address are returned)
    cout << "After chained call (pointer):" << endl;
    p_dog1->set_name("Bobbie")->set_dog_breed("Infertile")->set_dog_age(3);      //str passing as 'const char'
    p_dog1->print_info();
    
    //reference version (use . because object are returned)
    cout << "After chained call (reference):" << endl;
    p_dog1->set_name_r("Casy").set_dog_breed_r("Unknown").set_dog_age_r(7);
    p_dog1->print_info();

    cout << endl;
    delete p_dog1;
    cout << endl;

    return 0;

}

void Dog::print_info(){
    cout << "Name:  " << this->dog_name << endl;
    cout << "Breed: " << this->dog_breed << endl;
    cout << "Age:   " << *(this->dog_age) << endl;
}