#include <iostream>
#include <string>
#include <string_view>
using namespace std;

//Constructor & Destructor call order
//Constructor are called in 1,2,3,4 order and destructor are called in reverse order (i.e. 4,3,2,1)
//because delete the last object first to ensure newer object have no object dependencies to older object
class Dog{

    //declaration
    public:
        //constructor header
        Dog();
        Dog(string_view name_param, string_view breed_param, int age_param);   //string_view are read only (faster)

        //destructor header
        ~Dog();

    private:
        string dog_name;
        string dog_breed;
        int* dog_age {nullptr};

};

int main(){

    Dog dog1("Test1","Fertile",4);
    Dog dog2("Test2","Fertile",2);
    Dog dog3("Test3","Fertile",6);
    Dog dog4("Test4","Fertile",3);

    cout << "Done!" << endl;

    return 0;

}

//constructor definition
Dog::Dog(){
    dog_name = "None";
    dog_breed = "None";
    dog_age = new int;      //dynamic memory allocation
    *dog_age = 0;
}
Dog::Dog(string_view name_param, string_view breed_param, int age_param){
    dog_name = name_param;
    dog_breed = breed_param;
    dog_age = new int;      //dynamic memory allocation
    *dog_age = age_param;
    cout << "Dog constructor called for " << dog_name << "." << endl;
}

//destructor definition
Dog::~Dog(){
    delete dog_age;                     //release memory on member pointer variable 
    cout << "Dog destructor called for " << dog_name << "." << endl;
}