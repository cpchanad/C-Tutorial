#include <iostream>
#include <string>
using namespace std;

//'Struct' keyword

//Members private by default
class Dog{
    
    string name {"Alex"};  //private by default

    public:
        void get_name(){
            cout << name << endl;
        }
};

//Members public by default
struct Cat{
    string name {"Casey"};  //public by default
};

//Use struct to form object only have pulic member variables or functions
struct Point{
    //Constructor
    Point() = default;
    Point(double x_value, double y_value){
        x = x_value;
        y = y_value;
    }
    //Variables
    double x;
    double y;
    //methods
    void print_xy(){
        cout << "[" << x << " ," << y << "]" << endl;
    }
};

void print_point(const Point& point){       //pass object as reference and will not be destructed when function die
    cout << "[" << point.x << " ," << point.y << "]" << endl;
}

int main(){

    Dog dog_1;
    Cat cat_1;

  //cout << dog_1.name << endl;    // -> error
    dog_1.get_name();              // use public function
    cout << cat_1.name << endl;
    cout << endl;

    Point pt1(2,4);
    cout << pt1.x << endl;
    cout << pt1.y << endl;
    cout << endl;

    Point pt2;
    pt2.x = 12;
    pt2.y = 24;
    pt2.print_xy();
    print_point(pt2);    //pass in object

    return 0;

}