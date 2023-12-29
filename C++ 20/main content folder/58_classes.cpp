#include <iostream>
#include <string>
#define PI 3.14159265359
using namespace std;

//Classes
//Build your own type like variable
//Blueprint -> object1,obj2,obj3....

class Cylinder{
    //member variables
    //can be stack or pointer variables, but not reference (reference cannot be uninitialized)
    public:            //public: variables can get access from outside of the class
        double base_radius {1.0};
        double height {1.0};
    
    private:           //private: cannot get access from outside of the class
        double secert_hole_width {1.0};
        double randtest;

    //member functions or methods
    public:            //if not put 'public:' here, by defalut its private
        double volume(){
            return PI * base_radius * base_radius * height;
        }
        double remaining_volume(){
            return volume() - hole_volume();
        }
    
    private:
        double hole_volume(){
            return secert_hole_width * secert_hole_width * height;
        }
};   //add semi-colon at the end

//private means you cannot use the variable or function outside the Cylinder class (the scope)
//you cannot use in the main() function below unless you put public in front
int main(){

    Cylinder cy1;  //declare cy1 object with Cylinder type
    Cylinder cy2;

    cy1.base_radius = 3.0;
    cy1.height = 5.5;
    cout << "cy1 object" << endl;
    cout << "r: " << cy1.base_radius << endl;
    cout << "h: " << cy1.height << endl;
    cout << "V: " << cy1.volume() << endl;
    cout << endl;

    cy2.base_radius = 2.0;
    cy2.height = 2.5;
    cout << "cy2 object" << endl;
    cout << "r: " << cy2.base_radius << endl;
    cout << "h: " << cy2.height << endl;
    cout << "V: " << cy2.volume() << endl;
    cout << endl;

    /*
    cy1.secert_hole_width = 2.0;
    cout << cy1.hole_volume() << endl;
    */
    //error -> can't get access because main() is outside of the class

    cout << "Remaining V: " << cy2.remaining_volume() << endl;
    //can go into public function of the class and get access to private variable or function

    return 0;

}