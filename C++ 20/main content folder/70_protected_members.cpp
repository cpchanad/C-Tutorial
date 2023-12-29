#include <iostream>
#include <string>
#include <string_view>
using namespace std;

//Protected members ('protected' keyword)
//protected access specifier: derived class have access to private member in base class
//                            but outside the class still do not have access
class Person{

    friend ostream& operator<<(ostream& out, const Person& person);

    public:
        Person() = default;
        Person(string_view first_name_param, string_view last_name_param);
        ~Person();

        //Getter
        string get_first_name() const{     //need to add 'const'
            return first_name;
        }
        string get_last_name() const{      //need to add 'const'
            return last_name;
        }

  //private:                       *change from private to protected*
    protected:
        string first_name {"None"};
        string last_name {"None"};
};

class Player: public Person{

    friend ostream& operator<<(ostream& out, const Player& player);

    public:
        Player() = default;
        Player(string_view game_param);
        ~Player();

        //Setter
        void set_first_name(string_view fn){ //derived class now have access to base class protected member variables
            first_name = fn;
        }
        void set_last_name(string_view ln){
            last_name = ln;
        }

    private:
        string m_game {"None"};
};

int main(){

    //setter function are now inside player class 
    Player p1("Baskeball");
    cout << p1 << endl;
    p1.set_first_name("Alex");
    p1.set_last_name("Christophr");
    cout << p1 << endl;
    /*
    p1.first_name = "Bobby";
    p1.last_name = "Snow"      -> error  beacuse you can't use it here (only within derived class)
    */

    return 0;

}

ostream& operator<<(ostream& out, const Player& player){
    out << "Player : [ game : " << player.m_game
        << " , name : " << player.get_first_name()
        << " " << player.get_last_name() << "]";
    return out;
}

Person::Person(string_view first_name_param, string_view last_name_param){
    first_name = first_name_param;
    last_name = last_name_param;
}

Person::~Person(){

}

Player::Player(string_view game_param){ 
    m_game = game_param; 
    first_name = "John";          //derived class now have access to base class protected member variables
    last_name = "Snow";
}

Player::~Player(){

}