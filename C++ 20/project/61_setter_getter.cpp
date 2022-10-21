#include <iostream>
#include <string>
#define PI 3.14159265
using namespace std;

//Setter and Getter
//placed in public and are methods
//provide access to private variables from main() function

class Cylinder{
    private:
        double base_radius {1.0};
        double height {1.0};

    public: 
        //constructors
        Cylinder() = default;
        //compiler will create an empty constructor
        Cylinder(double rad_param, double hei_param){
            base_radius = rad_param;
            height = hei_param;
        }

        //Getters
        double get_base_radius(){
            return base_radius;
        }
        double get_height(){
            return height;
        }

        //Setters
        void set_base_radius(double radius_param){
            base_radius = radius_param;
        }
        void set_height(double height_param){
            height = height_param;
        }
        
        //methods
        double volume(){
            return PI * base_radius * base_radius * height;
        }
};

int main(){

    Cylinder cy1(2,3);
    cout << "r: " << cy1.get_base_radius() << endl;
    cout << "h: " << cy1.get_height() << endl;
    cout << "V: " << cy1.volume() << endl;
    cout << endl;

    cy1.set_base_radius(3.0);
    cy1.set_height(5.0);
    cout << "r: " << cy1.get_base_radius() << endl;
    cout << "h: " << cy1.get_height() << endl;
    cout << "V: " << cy1.volume() << endl;

    return 0;

}