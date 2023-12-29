#include <iostream>
#include <string>
#include <string_view>
#define PI 3.14159
using namespace std;

//Pure virtual function and abstract classes
//Pure virtual function : they are setup in base class without definition, purely for use in derived class object
//they are not supposed to be implemented in base class, they are meant to be overriden and implemented by inheritance classes
//Abstract class: compiler will prevent you creating base class object
//base class is a representation of all derived class object without going into concrete implementation

//***'Shape' is an abstract class once pure virtual functions are created
class Shape{
    protected:
        //protected/public constructor (***not allow to make object once its an abstract class)
        Shape() = default;
        Shape(string_view name_param)
            :name(name_param){}
    public:
        //public destructor -> to allow base_ptr to be deleted
        virtual ~Shape() = default;

        //pure virtual functions (***no definition or implementation here)
        virtual double perimeter() const = 0;
        virtual double surface() const = 0;

        //method
        string get_name() const{
            return name;
        }
    private:
        string name {"None"};
};

class Rectangle: public Shape{
    public:
        //public constructor
        Rectangle() = default;
        Rectangle(double m_length, double m_width, string_view name_param)
            :Shape(name_param), length(m_length), width(m_width){}
        //public destructor -> to allow base_ptr to be deleted
        virtual ~Rectangle() = default;

        //override pure virtual functions in base class (***must explicitly override all pure function)
        virtual double perimeter() const override{        //otherwise, dervied class will become abstract
            return 2*(length + width);
        }
        virtual double surface() const override{
            return length * width;
        }
    private:
        double length {};
        double width {};
};

class Circle: public Shape{
    public:
        //public constructor
        Circle() = default;
        Circle(double m_r_radius, string_view name_param)
            :Shape(name_param), r_radius(m_r_radius){}
        //public destructor -> to allow base_ptr to be deleted
        virtual ~Circle() = default;

        //override pure virtual functions in base class (***must explicitly override all pure function)
        virtual double perimeter() const override{        //otherwise, dervied class will become abstract
            return 2*PI*r_radius;
        }
        virtual double surface() const override{
            return PI*r_radius*r_radius;
        }
    private:
        double r_radius {};
};

int main(){

  //Shape* shape = new Shape;      //-> error: shape is an abstract class
                                             //can't create object of an abstract class
    
    //using base pointer to manage derived object
    const Shape* shape_rect = new Rectangle(5,5,"rect_1");
    cout << shape_rect->get_name() << endl;
    cout << "dynamic type of shape_rect: " << typeid(*shape_rect).name() << endl;
    cout << "The perimeter of shape_rect is " << shape_rect->perimeter() << endl;
    cout << "The surface of shape_rect is " << shape_rect->surface() << endl;

    cout << endl;

    const Shape* shape_circle = new Circle(5,"circle_1");
    cout << shape_circle->get_name() << endl;
    cout << "dynamic type of shape_rect: " << typeid(*shape_circle).name() << endl;
    cout << "The perimeter of shape_circle is " << shape_circle->perimeter() << endl;
    cout << "The surface of shape_circle is " << shape_circle->surface() << endl;

    //release memory
    delete shape_rect;
    delete shape_circle;

    return 0;

}