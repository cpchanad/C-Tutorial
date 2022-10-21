#include <iostream>
#include <string>
#define PI 3.14159265
using namespace std;

//Defaulted Constructor
class Cylinder{
    private:
        double base_radius {1.0};
        double height {1.0};
    public:
        Cylinder() = default;     //auto-generate empty constructors
        //add this line when you need a default constructor
        //e.g. you added a custom constructor like below, a default constructor will no longer be created by default

        Cylinder(double radius_param, double height_param){
            base_radius = radius_param;
            height = height_param;
        }
        double volume(){
            return PI * base_radius * base_radius * height;
        }
};

int main(){

    Cylinder cy1;
    cout << cy1.volume() << endl;

    return 0;

}