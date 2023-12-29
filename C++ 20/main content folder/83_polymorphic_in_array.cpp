#include <iostream>
#include <string>
#include <memory>            //to use smart pointer
using namespace std;

//polymorphic object stored in collections

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
        virtual void draw() const{
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
        virtual void draw() const{
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

    //store object in array will create copies, not reference
    Shape shape_collection[] {c1,o1,c2,o2,c3,o3};            //this will slice off oval & circle info
    cout << "Outside array, sizeof(shape): " << sizeof(c1) << endl;
    cout << endl;

    cout << "Shape array: " << endl;
    for(Shape& s: shape_collection){   //use reference to avoid copies
        cout << "Inside array, sizeof(shape): " << sizeof(s) << endl;
        s.draw();
    }

    //storing in references in array will not work
  //const Shape& shape_collection_2[] {c1,o1,c2,o2,c3,o3};  -> error  //compiler don't allow reference array
    //can't reuse reference variable to point to other variables
    cout << endl;
 
    //storing in raw pointer in array
    Shape* shape_collection_3[] {&c1,&o1,&c2,&o2,&c3,&o3};   //this will not slice off information
    cout << "Outside array, sizeof(shape): " << sizeof(c1) << endl;
    cout << endl;

    cout << "Shape pointer array: " << endl;
    for(Shape* s_ptr: shape_collection_3){
        cout << "Inside array, sizeof(*shape_ptr): " << sizeof(*s_ptr) << endl;
        s_ptr->draw();
    }
    cout << endl;
    
    //storing in smart pointer in array
    shared_ptr<Shape> shape_collection_4[] {make_shared<Circle>(12.2,"Circle_4"), make_shared<Oval>(10.0,20.0,"Oval_4")};

    for(auto& s: shape_collection_4){   //use reference to avoid copies
        s->draw();
    }

    return 0;

}