#include <iostream>
#include <string>
#define PI 3.14159265
using namespace std;

//Managing class object through pointer
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

    //create class object on the stack (stack object)
    Cylinder cy1(10,2);
    Cylinder* p_cy1 = &cy1;
    cout << "Cy1 Address: " << p_cy1 << endl;
    cout << "Cy1 Volume: " << cy1.volume() << endl;
    cout << "Cy1 Volume: " << (*p_cy1).volume() << endl;
    cout << "Cy1 Volume: " << p_cy1->volume() << endl;
    cout << endl;

    //create class object on the heap (heap object)
    Cylinder* p_cy2 {new Cylinder(11,20)};
    cout << "Cy2 Address: " << p_cy2 << endl;
    cout << "Cy2 Volume: " << (*p_cy2).volume() << endl;   //dereference and . notation
    cout << "Cy2 Volume: " << p_cy2->volume() << endl;     //-> notation

    //release memory from heap, otherwise memory leak
    delete p_cy2;

    return 0;

}