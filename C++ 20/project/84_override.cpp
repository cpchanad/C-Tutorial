#include <iostream>
#include <string>
using namespace std;

//override specification
//to avoid error in inheritance hierarchies if virtual functions is used
//virtual function in child class will override or hide parent class function

class Shape{
    public:
        //constructor & destructor
        Shape() = default;
        Shape(string_view name_param)
            :name(name_param){}
        ~Shape(){}
        //method
        virtual void draw() const{
            cout << "Shape::draw() called. Drawing " << name << endl;
        }
    protected:
        string name {"None"};
};

class Oval: public Shape{
    public:
        //constructor & destructor
        Oval() = default;
        Oval(double m_x_radius, double m_y_radius, string_view name_param)
            :Shape(name_param), x_radius(m_x_radius), y_radius(m_y_radius){}
        ~Oval(){}
        //methods
        virtual void draW() const override{   //add 'override' specification to indicate error
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
        virtual void DraW() const override{   //add 'override' specification to indicate error
            cout << "Circle::draw() called. Drawing " << name << " with r_radius : " <<
                r_radius << endl;
        }
    private:
        double r_radius {};
};

int main(){

    Circle c1(7.2,"Circle_1");
    Oval o1(13.3,1.2,"Oval_1");
    Circle c2(11.2,"Circle_2");
    Oval o2(31.3,15.2,"Oval_2");
    Circle c3(15.2,"Circle_3");
    Oval o3(53.3,50.2,"Oval_3");

    Shape* shape_collection_3[] {&c1,&o1,&c2,&o2,&c3,&o3};

    for(Shape* s_ptr: shape_collection_3){
        cout << "Inside array, sizeof(*shape_ptr): " << sizeof(*s_ptr) << endl;
        s_ptr->draw();
    }

    return 0;

}