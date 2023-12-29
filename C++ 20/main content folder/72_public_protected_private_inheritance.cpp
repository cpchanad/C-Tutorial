#include <iostream>
#include <string>
#include <string_view>

#include "72_person.h"    // this inlcude is optional
#include "72_player.h"
#include "72_nurse.h"
#include "72_engineer.h"
using namespace std;

//Public, Protected & private inheritance
//Public inheritance do not change any access criteria
//Protected inheritance change <'public' to base class> to <'protected' to derived class>
//Private inheritance change <'public' to base class> to <'private' to derived class>
//                           <'protected' to base class> to <'private' to derived class>

int main(){

    Person p1("Alex Christopher",27,"23 Blue Sky Stress");
    cout << p1 << endl;
    cout << endl;

    //public inheritance
    Player p2(2015,12000.0,7);
    p2.play();
    cout << p2 << endl;
    p2.m_fullname = "Samuel Jackson";   // OK    because 'public' to base class allow access outside derived derived class
  //p2.m_age = 0;                      -> error  because 'protected' to base class not allow access outside derived derived class
  //p2.m_address = "";                 -> error  because 'private' to base class not allow access outside derived derived class
    cout << p2 << endl;
    cout << endl;

    //protected inheritance
    Nurse p3(20201382);
    p3.treat_unwell_person();
    cout << p3 << endl;
  //p3.m_fullname = "";                -> error  because 'protected' to nurse class not allow access outside derived class
  //p3.m_age = 0;                      -> error  because 'protected' to base class not allow access outside derived derived class
  //p3.m_address = "";                 -> error  because 'private to base class' not allow access outside derived derived class
    cout << p3 << endl;
    cout << endl;

    //private inheritance
    Engineer p4(30);
    p4.build_something();
  //p4.m_fullname = "";                -> error  because 'private' to engineer class not allow access outside derived class
  //p4.m_age = 0;                      -> error  because 'private' to engineer class not allow access outside derived class
  //p4.m_address = "";                 -> error  because 'private' to base class not allow access outside derived derived class
    cout << p4 << endl;

    //protected inheritance -> public inheritance
    intern_nurse p5;
    p5.treat_practice();
  //p5.m_fullname = "";                -> error  because 'protected' to nurse class not allow access outside derived class           
  //p5.m_age = 0;                      -> error  because 'protected' to base class not allow access outside derived derived class
  //p5.m_address = "";                 -> error  because 'private to base class' not allow access outside derived derived class
    cout << p5 << endl;

    //private inheritance -> public inheritance
    civil_engineer p6;
    p6.build_bridge();
  //p6.m_fullname = "";                -> error  because 'private' to engineer class not allow access outside derived class
  //p6.m_age = 0;                      -> error  because 'private' to engineer class not allow access outside derived class
  //p6.m_address = "";                 -> error  because 'private' to base class not allow access outside derived derived class
    cout << p6 << endl;
    p6.build_something();         //OK  becuase 'public' to engineer class (not inheritance) allow acess outside derived class
    cout << p6 << endl;

    return 0;

}