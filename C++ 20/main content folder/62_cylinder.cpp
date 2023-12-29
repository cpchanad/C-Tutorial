#include "62_cylinder.h"
#include "62_constants.h"

//class definition
//add 'class type custom name' and then two colon '::' after return type and before function name
//to indicate classes scope              (scope resolutional operator)

//constructor definition
Cylinder::Cylinder(double rad_param, double hei_param){
    base_radius = rad_param;
    height = hei_param;
}

//Getters definition
double Cylinder::get_base_radius(){
    return base_radius;
}
double Cylinder::get_height(){
    return height;
}

//Setters definition
void Cylinder::set_base_radius(double radius_param){
    base_radius = radius_param;
}
void Cylinder::set_height(double height_param){
    height = height_param;
}
        
//methods definition
double Cylinder::volume(){
    return PI * base_radius * base_radius * height;
}

double test_1 = TEST;