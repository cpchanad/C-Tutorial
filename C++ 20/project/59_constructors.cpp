#include <iostream>
#include <string>
#define PI 3.14159265
using namespace std;

//Class constructors
//A special kind of method that is called when an instance of a class is created
//1. No return type
//2. Same name as the class
//3. Can have parameters or empty parameter list
//4. usually used to initialize member variables of a class

class Cylinder{
    //properties
    private:
        double base_radius {1.0};
        double height {1.0};

    //behaviors
    public:
        //constructor have to be public
        //constructor are special methods called by the compiler to initialize class object
        //have same name as class and no return type in front

        //Default constructor (if no constructor declared, empty constructor by default)
        //constructor with no parameters to initialize member variables
        Cylinder(){
            base_radius = 2.0;
            height = 2.0;
        }
        //constructor that take parameters (passed by value)
        Cylinder(double radius_param, double height_param){
            base_radius = radius_param;
            height = height_param;
        }

        //custom method
        double volume(){
            return PI * base_radius * base_radius * height;
        }
};

int main(){

    Cylinder cy1;                   //Bulid an object from an constructor(if exist)
    cout << "V: " << cy1.volume() << endl;

    Cylinder cy2(3,5.5);
    cout << "V: " << cy2.volume() << endl;

    return 0;

}