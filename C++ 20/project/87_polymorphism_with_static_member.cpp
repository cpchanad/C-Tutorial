#include <iostream>
#include <string>
#include <string_view>
#include <memory>
using namespace std;

//Polymorphism with static members

class Shape{
    public:
        Shape(){++m_count;}           //increment of shape count when it is created
        Shape(string_view m_name)
            :name(m_name){++m_count;}
        virtual ~Shape(){--m_count;}

        void draw() const{
            cout << "Shape::draw() called for: " << name << endl;
        }

        //polymorphism
        virtual int get_count() const{
            return m_count;
        }

        //static variable:
        //Only one copy of that member is created for the entire class and is shared by all the objects of that class,
        //no matter how many objects are created.
        static int m_count;      //cannot initialize inside the class
                                 //exist in class scope
                                 //declaration only execute one time only
    protected:
        string name {"None"};
};

//initialize static variables
int Shape::m_count {0};          //only outside class & not inside main() can initialize

class Ellipse: public Shape{
    public:
        Ellipse(){++m_count;}           //increment of ellipse count when it is created
        Ellipse(double m_x_radius, double m_y_radius, string_view m_name)
            :Shape(m_name), x_radius(m_x_radius), y_radius(m_y_radius){++m_count;}
        virtual ~Ellipse(){--m_count;}

        //override the Shape function through polymorphism (if use base pointer)
        virtual int get_count() const override{
            return m_count;
        }

        //setup another static variable with exact the same name
        //Ellipse will maintain its own static variable & Shape will have its own too
        static int m_count;        //two separate static variable in different class with inheritance

    private:
        double x_radius {0.0};
        double y_radius {0.0};
};

//initialize static variables having the same name with different class
int Ellipse::m_count {0};

int main(){

    Shape s1("shape1");
    cout << "shape count: " << Shape::m_count << endl;

    Shape s2("shape2");
    cout << "shape count: " << Shape::m_count << endl;

    Shape s3("shape3");
    cout << "shape count: " << Shape::m_count << endl;

    //two different static variable in each class
    Ellipse e1(10,12,"ellipse1");
    cout << "shape count: " << Shape::m_count << endl;        //4 
    cout << "ellipse count: " << Ellipse::m_count << endl;    //1 

    cout << endl;
    cout << e1.m_count << endl;         //it will use its own static variable by default
    cout << e1.Shape::m_count << endl;  //specify to use parent static variable

    cout << endl;

    //polymorphism with static variable
    Ellipse e2(2,4,"ellipse2");
    Ellipse e3(2.3,4.6,"ellipse3");
    Ellipse e4(3.5,8.5,"ellipse4");

    Shape* shape_collection[] {&s1,&s2,&s3,&e1,&e2,&e3,&e4};

    for(const auto& shape: shape_collection){
        cout << shape->get_count() << endl;        //call the most specific function & the correct static variable
    }                                              // shape count = 7
                                                   // ellipse count = 4

    cout << endl;

    //polymorphism with smart pointer
    {   
        //nested scope: using shared pointers so that objects are destroyed automatically without us calling delete

        //create smart pointer object
        shared_ptr<Shape> shapes[] {make_shared<Ellipse>(10,10,"ellipse_at_0"), 
            make_shared<Ellipse>(12,43,"ellipse_at_1")};

        cout << "Shape count (Nested scope): " << Shape::m_count << endl;     //9
        cout << "Ellipse count (Nested scope): " << Ellipse::m_count << endl; //6
    }

    return 0;

}