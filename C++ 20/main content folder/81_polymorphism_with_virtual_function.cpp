#include <iostream>
#include <string>
#include <string_view>
using namespace std;

//Polymorphism (dynamic binding) with virtual function
//mark the method that need to be dynamically resolved using 'virtual' keyword
//the compiler will know not to use the base pointer but use derived class object type to decide which class method to use

class Shape{
    public:
        //constructor & destructor
        Shape() = default;
        Shape(string_view name_param)
            :name(name_param){}
        ~Shape(){}
        //method (have the same name as all other class)
        virtual void draw() const{                                     //add 'virtual' infront of the function
            cout << "Shape::draw() called. Drawing " << name << endl;  //to use dynamic binding
        }
        virtual double get_radius_vir(){ //this function are virtual & derived class method will called instead
            return 0.0;
        }
        double get_radius(){             //this function are not virtual & only base class method will called
            return 0.0;
        }
    protected:
        string name {"None"};
};

class Rectangle: public Shape{
    public:
        //constructor & destructor
        Rectangle() = default;
        Rectangle(double m_length, double m_width, string_view name_param)
            :Shape(name_param), length(m_length), width(m_width){}
        ~Rectangle(){}
        //methods (have the same name as all other class)
        virtual void draw() const{                                        //add 'virtual' infront of the function(optional)
            cout << "Rectangle::draw() called. Drawing " << name << " with length : " << //to use dynamic binding
                length << " and width : " << width << endl;
        }
    private:
        double length {};
        double width {};
};

class Oval: public Shape{
    public:
        //constructor & destructor
        Oval() = default;
        Oval(double m_x_radius, double m_y_radius, string_view name_param)
            :Shape(name_param), x_radius(m_x_radius), y_radius(m_y_radius){}
        ~Oval(){}
        //methods (have the same name as all other class)
        virtual void draw() const{                                        //add 'virtual' infront of the function(optional)
            cout << "Oval::draw() called. Drawing " << name << " with x_radius : " <<    //to use dynamic binding
                x_radius << " and y_radius : " << y_radius << endl;
        }
        //function
        virtual double get_x_radius(){     //this function are virtual but not exist in base class
            return x_radius;               //therefore, cannot be used with base pointer/reference
        }
        double get_y_radius(){             //this function are not virtual & not exist in base class
            return y_radius;               //therefore, cannot be used with base pointer/reference
        }
    private:
        double x_radius {};
        double y_radius {};
};

class Circle: public Oval{
    public:
        //constructor & destructor
        Circle() = default;
        Circle(double m_r_radius, string_view name_param)
            :Oval(m_r_radius, m_r_radius, name_param){
                r_radius = m_r_radius;
            }
        ~Circle(){}
        //methods (have the same name as all other class)
        virtual void draw() const{                                        //add 'virtual' infront of the function(optional)
            cout << "Circle::draw() called. Drawing " << name << " with r_radius : " <<  //to use dynamic binding
                r_radius << endl;
        }
        //function
        double get_radius_vir(){         //this function are virtual & exist in base class
            return r_radius;             //therefore, can be used with base pointer/reference
        }
        double get_radius(){             //this function are not virtual & cannot be used with base pointer/reference
            return r_radius;
        }
    private:
        double r_radius {};
};

//Passing base pointers or references to functions
//pointer version
void draw_shape_point(Shape* shape_ptr){
    shape_ptr->draw();                    // Call the right method for the kind of object passed in
}
//reference version
void draw_shape_ref(const Shape& shape_obj){
    shape_obj.draw();                     // Call the right method for the kind of object passed in
}

int main(){

    //objective: to call a method on the base pointer/reference and get the derived class method to be called

    //1.Dynamic binding with base class pointer
    //to solve the problem that compiler look at the pointer type to decide which class method (draw() version) to be called
    //by using 'virtual' keyword
    Shape shape_2("Shape");
    Oval oval_2(2,3.5,"Oval");
    Circle circle_2(3.5,"Circle");

    cout << "Calling methods through pointers: dynamic binding" << endl;
    Shape* shape_ptr {nullptr};

    //By default, 'shape*' pointer will only call Shape::method()
    //using 'virtual' keyword to change to dynamic binding
    shape_ptr = &shape_2;                                            //can use the same pointer variable to point to
    shape_ptr->draw();                                               //different object address 
    shape_ptr = &oval_2;
    shape_ptr->draw();       // Oval::draw() to be called
    shape_ptr = &circle_2;
    shape_ptr->draw();       // Circle::draw() to be called

    cout << endl;

    //1.Dynamic binding with base class reference
    //to solve the problem that compiler look at the reference type to decide which class method (draw() version) to be called
    //by using 'virtual' keyword
    cout << "Calling methods through references: dynamic binding" << endl;

    //By default, 'shape&' reference will only call Shape::method()
    //using 'virtual' keyword to change to dynamic binding
    Shape& shape_ref_1 = shape_2;                                     //need to setup new variable for each reference
    shape_ref_1.draw();
    Shape& shape_ref_2 = oval_2;
    shape_ref_2.draw();       // Oval::draw() to be called
    Shape& shape_ref_3 = circle_2;
    shape_ref_3.draw();       // Circle::draw() to be called

    cout << endl;
    cout << "===================================================" << endl;

    //2.calling main() function using base class type
    cout << "Calling main() function: dynamic binding" << endl;
    draw_shape_point(shape_ptr);
    draw_shape_ref(shape_ref_2);
    cout << endl;

    //3.Store base class pointers in a collection like array
    //  allow different derived class type objects to store in the same 'base class type'array
    Circle c1(7.2,"Circle_1");
    Oval o1(13.3,1.2,"Oval_1");
    Circle c2(11.2,"Circle_2");
    Oval o2(31.3,15.2,"Oval_2");
    Circle c3(15.2,"Circle_3");
    Oval o3(53.3,50.2,"Oval_3");

    //array store data of the same type: all shape pointers with different derived class type
    Shape* shape_collection[] {&c1, &o1, &c2, &o2, &c3, &o3};

    cout << "===================================================" << endl;
    cout << "Calling functions through array: dynamic binding: " << endl;
    cout << endl;
    //for loop to loop shape pointers inside an array
    for(Shape* shape_ptr: shape_collection){
        cout << "Inside array, sizeof(*shape_ptr): " << sizeof(*shape_ptr) << endl;
        shape_ptr->draw();                // Call the right method for the kind of object passed in
        cout << endl;
    }

    //Extra. *base pointer/reference cannot call 1. function not inside base class (even though obj has same class type)
    //                                        or 2. function that are not virtual in base class

    //not exist in base class (does not matter virtual or not)
  //cout << shape_ref_2.get_x_radius() << endl;    ->error
  //cout << shape_ref_2.get_y_radius() << endl;    ->error

    //exist in base class
    cout << shape_ref_3.get_radius_vir() << endl;     //circle class method called because its virtual
    cout << shape_ref_3.get_radius() << endl;         //base class method will call if not virtual

    return 0;

}