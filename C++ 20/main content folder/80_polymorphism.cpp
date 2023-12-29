#include <iostream>
#include <string>
#include <string_view>
using namespace std;

//Polymorphism
//A setup that use base class pointer/ base class reference to manage derived object in inheritance hierachies.

//Using a common base class type to
//1.allow a common name methods/functions (but contents specific to their own type)
//  to be called even though they are of different derived class type
//2.allow different derived type object to store in collection (the same array)

class Shape{
    public:
        //constructor & destructor
        Shape() = default;
        Shape(string_view name_param)
            :name(name_param){}
        ~Shape(){}
        //method (have the same name as all other class)
        void draw() const{
            cout << "Shape::draw() called. Drawing " << name << endl;
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
        void draw() const{
            cout << "Rectangle::draw() called. Drawing " << name << " with length : " <<
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
        void draw() const{
            cout << "Oval::draw() called. Drawing " << name << " with x_radius : " <<
                x_radius << " and y_radius : " << y_radius << endl;
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
        void draw() const{
            cout << "Circle::draw() called. Drawing " << name << " with r_radius : " <<
                r_radius << endl;
        }
    private:
        double r_radius {};
};

//1.Passing base pointers or references to functions
//***common name method/functions*** for base class type object
//No need to create a lot of method for different derived class object

//pointer version
void draw_shape_point(Shape* shape_ptr){
    shape_ptr->draw();                    // Call the right method for the kind of object passed in
}
//reference version
void draw_shape_ref(const Shape& shape_obj){
    shape_obj.draw();                     // Call the right method for the kind of object passed in
}

int main(){

    //1.Using Shape type pointer or reference to store derived class object
    //Circle, Rectangle & Oval are all inherited from Shape base class (i.e. they are all 'Shape' type object)
    //***common base class type***

    //pointer: dynamically allocate new object
    Shape* shape_circle_ptr = new Circle;
    Shape* shape_rectangle_ptr = new Rectangle;
    Shape* shape_oval_ptr = new Oval;

    //reference
    Circle Circle_1;
    Rectangle Rectangle_1;
    Oval Oval_1;
    Shape& ref_shape_circle {Circle_1};
    Shape& ref_shape_rectangle {Rectangle_1};
    Shape& ref_shape_oval {Oval_1};

    //2.Static binding with base class pointer
    //compiler look at the pointer type to decide which class method (draw() version) to be called
    Shape shape_2("Shape");
    Oval oval_2(2,3.5,"Oval");
    Circle circle_2(3.5,"Circle");

    cout << "Calling methods through pointers: static binding" << endl;
    Shape* shape_ptr {nullptr};

    //By default, 'shape*' pointer will only call Shape::method()
    shape_ptr = &shape_2;
    shape_ptr->draw();
    shape_ptr = &oval_2;
    shape_ptr->draw();       // would wish for Oval::draw() to be called
    shape_ptr = &circle_2;
    shape_ptr->draw();       // would wish for Circle::draw() to be called

    cout << endl;

    //2.Static binding with base class reference
    //compiler look at the reference type to decide which class method (draw() version) to be called
    cout << "Calling methods through references: static binding" << endl;

    //By default, 'shape&' reference will only call Shape::method()
    Shape& shape_ref_1 = shape_2;
    shape_ref_1.draw();
    Shape& shape_ref_2 = oval_2;
    shape_ref_2.draw();       // would wish for Oval::draw() to be called
    Shape& shape_ref_3 = circle_2;
    shape_ref_3.draw();       // would wish for Circle::draw() to be called

    cout << endl;

    //2.Dynamic binding
    //objective: to call a method on the base pointer/reference and get the derived class method to be called
    /*
    
        in the next lecture
    
    */

   cout << "=================================================" << endl;
   //3.calling main() function 
   cout << "static binding: " << endl;
   draw_shape_point(shape_ptr);
   draw_shape_ref(shape_ref_2);
   cout << endl;

   cout << "=================================================" << endl;
   cout << "static binding: " << endl;
    //4.Store base class pointers in a collection like array
    //  allow different derived class type objects to store in the same 'base class type'array
    Circle c1(7.2,"Circle_1");
    Oval o1(13.3,1.2,"Oval_1");
    Circle c2(11.2,"Circle_2");
    Oval o2(31.3,15.2,"Oval_2");
    Circle c3(15.2,"Circle_3");
    Oval o3(53.3,50.2,"Oval_3");

    //array store data of the same type: all shape pointers with different derived class type
    Shape* shape_collection[] {&c1, &o1, &c2, &o2, &c3, &o3};

    //for loop to loop shape pointers inside an array
    for(Shape* shape_ptr: shape_collection){
        cout << "Inside array, sizeof(*shape_ptr): " << sizeof(*shape_ptr) << endl;
        shape_ptr->draw();                // Call the right method for the kind of object passed in
        cout << endl;
    }

    //release memory
    delete shape_circle_ptr;
    delete shape_rectangle_ptr;
    delete shape_oval_ptr;

    return 0;

}