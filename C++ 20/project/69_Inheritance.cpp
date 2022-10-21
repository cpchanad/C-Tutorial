#include <iostream>
#include <string>
#include "69_player.h"
using namespace std;

//Inheritance
//allow us to build classes in terms of other classes (code reuse)
//Fundamental class on top, derived class on bottom

//Derived class (public inheritance) can have access and use public variable & function in base class
int main(){

    Player p1("Basketball","Alex","Christopher");  //directly written-out "Basketball" string cannot pass by reference,
    cout << p1 << endl;                            //use string_view
    p1.set_first_name("Bobby");
    p1.set_last_name("Snow");
    p1.set_game("Football");
    cout << p1 << endl;

    return 0;

}