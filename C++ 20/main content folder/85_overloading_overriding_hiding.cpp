#include <iostream>
#include <string>
using namespace std;

//Overloading, overriding and hiding
//overloading in virtual functions inside class & overriding with child class function
//need to setup each overloading virtual function in each class for polymorphism to work

class Shape{
    public:
        //constructor & destructor
        Shape() = default;
        Shape(string_view name_param)
            :name(name_param){}
        ~Shape(){}
        //overloading virtual method/functions: set up in each child class
        virtual void draw() const{
            cout << "Shape::draw() called. Drawing " << name << endl;
        }
        virtual void draw(int color_depth) const{
            cout << "Shape::draw(color_depth) called. Drawing with color depth (" <<
                color_depth << "): " << name << endl;
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
        //overloading methods
        virtual void draw() const override{
            cout << "Oval::draw() called. Drawing " << name << " with x_radius : " <<
                x_radius << " and y_radius : " << y_radius << endl;
        }
        virtual void draw(int color_depth) const override{
            cout << "Oval::draw(color_depth) called. Drawing with color depth (" <<
                color_depth << "): " << name << " with x_radius : " <<
                x_radius << " and y_radius : " << y_radius << endl;
        }
        //not exist in base class: not participate in polymorphism
        virtual void draw(int color_depth, string_view color) const{
            cout << "Oval::draw(color_depth) called. Drawing with color depth (" <<
                color_depth << " & " << color << "): " << name << " with x_radius : " <<
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
        //overloading methods
        virtual void draw() const override{
            cout << "Circle::draw() called. Drawing " << name << " with r_radius : " <<
                r_radius << endl;
        }
        virtual void draw(int color_depth) const override{
            cout << "Circle::draw(color_depth) called. Drawing with color depth (" <<
                color_depth << "): " << name << " with r_radius : " <<
                r_radius << endl;
        }
        //not exist in base class: not participate in polymorphism
        virtual void draw(int color_depth, string_view color) const{
            cout << "Circle::draw(color_depth) called. Drawing with color depth (" <<
                color_depth << " & " << color << "): " << name << " with r_radius : " <<
                r_radius << endl;
        }
    private:
        double r_radius {};
};

int main(){

    Oval o1(2.0,3.5,"Oval_1");
    Circle c1(3.3,"Circle_1");

    Shape* shape_collection[] {&o1,&c1};

    //overloading functions with polymorphism
    shape_collection[0]->draw();
    shape_collection[0]->draw(44);

    shape_collection[1]->draw();
    shape_collection[1]->draw(24);

    cout << endl;

    //Shape polymorphism with non top-level polymorphic methods
    o1.draw(30,"red");
    c1.draw(10,"red");

  //shape_collection[0]->draw(30,"red");  // -> error: shape pointer can't call function not participate in
  //shape_collection[1]->draw(10,"red");               base class polymorphism


    //Slicing with non top-level polymorphic methods
    Shape shape_1 = o1;
    Shape shape_2 = c1;
  //shape_1.draw(22, "yellow");   // -> error: shape object do not have function of child class
  //shape_2.draw(22, "yellow");
    

    return 0;

}