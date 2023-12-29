#ifndef CYLINDER_H
#define CYLINDER_H

//class declaration
//don't define here, only declaration
class Cylinder{
    private:
        double base_radius {1.0};
        double height {1.0};

    public: 
        //constructors header
        Cylinder() = default;
        Cylinder(double rad_param, double hei_param);  //be careful not to define the same function twice
                                                       //error will occur in linker stage
        //Getters header
        double get_base_radius();
        double get_height();

        //Setters header
        void set_base_radius(double radius_param);
        void set_height(double height_param);
        
        //methods header
        double volume();
};

#endif