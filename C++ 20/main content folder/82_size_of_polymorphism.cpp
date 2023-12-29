#include <iostream>
#include <string>
using namespace std;

//size of polymorphic objects and slicing
//dynamic binding require additional memory usage

class Shape{
    public:
        //constructor & destructor
        Shape() = default;
        Shape(string_view name_param)
            :name(name_param){}
        ~Shape(){}
        //method
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
        //methods
        void draw() const{         //non-virtual
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
        //methods
        virtual void draw() const{  //virtual
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
        //methods
        void draw() const{
            cout << "Circle::draw() called. Drawing " << name << " with r_radius : " <<
                r_radius << endl;
        }
    private:
        double r_radius {};
};

int main(){

    //comparing object sizes
    cout << "sizeof(Rectangle - 1st layer{without virtual}): " << sizeof(Rectangle) << endl;
    cout << "sizeof(Oval - 1st layer{with virtual}): " << sizeof(Oval) << endl;
    cout << "size differences due to dynamic binding: " << sizeof(Oval) - sizeof(Rectangle) << endl;
    cout << endl;
    //the size difference are virtual table which store additional data
    //to dynamically resovle virtual function call

    //slicing
    Shape shape_1("Shape1");
    Oval oval_1(2.0,3.5,"Oval1");
    Circle circle_1(3.0,"Circle1");

    circle_1.draw();
    cout << sizeof(circle_1) << endl;
    cout << endl;

    //assigning a circle object to a shape object (Not good)
    //raw object is different from base pointer/reference
    shape_1 = circle_1; //raw object

    //compiler will strip off all additional info that are not inclueded in 'shape' class
    //leaving only the 'name' part and only base class method will be called
    shape_1.draw();
    cout << sizeof(shape_1) << endl;

    return 0;

}