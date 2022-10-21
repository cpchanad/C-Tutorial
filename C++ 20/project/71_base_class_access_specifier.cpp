#include <iostream>
#include <string>
using namespace std;

//watch 72 not this one

//Base class access specifiers -> indicate how accessible base class members from a derived class
//'public' keyword: public inheritance         -> make base class member stay the same
//'protected' keyword: protected inheritance   -> make 'public' into 'protected'
//'private' keyword: private inheritance       -> make 'public' & 'protected' into 'private'
// can only put more constrain onto base class member variables, but not relax them more
class Person{

    friend ostream& operator<<(ostream& out, const Person& person);

    public:
        Person() = default;
        Person(string_view first_name_param, string_view last_name_param, int age_param);
        ~Person();

        //Getter
        string get_first_name() const{     //need to add 'const'
            return first_name;
        }
        string get_last_name() const{      //need to add 'const'
            return last_name;
        }
        int get_age() const{               //need to add 'const'
            return age;
        }
        //Setter
        void set_age(int age_param){
            age = age_param;
        }

    protected:
        string first_name {"None"};
        string last_name {"None"};
    
    private:
        int age {};
};

// 1. public inheritance
// public in base class -> stay public to base class       : have access within and outside derived class
// protected in base class -> stay protected to base class : have access within but not outside derived class
// private in base class -> stay private to base class     : do not have access within and outside derived class
class Player: public Person{    //'public' keyword -> base class access specifiers

    friend ostream& operator<<(ostream& out, const Player& player);

    public:
        Player() = default;
        Player(string_view game_param);
        ~Player();
    
        //Setter
        void set_player_first_name(string_view fn){
            first_name = fn;                       //protected -> have access within derived class
        }
        void set_player_last_name(string_view ln){ //protected -> have access within derived class
            last_name = ln;
        }
        void set_player_age(int age_param){
          //age = age_param;                       //private    -> do not have acess within derived class
            this->set_age(age_param);              //public     -> have acess within derived class
        }

    private:
        string m_game {"None"};
};

// 2. protected inheritance
// public in base class -> *protected* to derived class    : have access within but not outside derived class
// protected in base class -> stay protected to base class : have access within but not outside derived class
// private in base class -> stay private to base class     : do not have access within and outside derived class
class Engineer: protected Person{    //'protected' keyword -> base class access specifiers

    friend ostream& operator<<(ostream& out, const Player& player);

    public:
        Engineer() = default;
        Engineer(string_view major_param);
        ~Engineer();

        //Getter
        int get_engineer_age(){
            return this->get_age();
        }
        //Setter
        void set_engineer_first_name(string_view fn){
            first_name = fn;                          //protected -> have access within derived class
        }
        void set_engineer_last_name(string_view ln){  //protected -> have access within derived class
            last_name = ln;
        }
        void set_engineer_age(int age_param){
          //age = age_param;                          //private    -> do not have acess within derived class
            this->set_age(age_param);                 //protected  -> have acess within derived class
        }

    private:
        string m_major {"None"};
};

// 3. private inheritance
// public in base class -> *private* to derived class    : have access within but not outside derived class
// protected in base class -> *private* to derived class : have access within but not outside derived class
// private in base class -> stay private to base class   : do not have access within and outside derived class

int main(){

    //1. Public inheritance
    Player p1("Basketball");
    cout << p1 << endl;
  //p1.first_name = "Alex";                        //protected -> do not have access outside derived class
  //p1.last_name = "Christopher";     ->error      //protected -> do not have access outside derived class
    p1.set_player_first_name("Alex");              //can access through derived class function only
    p1.set_player_last_name("Christopher");

  //p1.age = 26;                                   //private   -> do not have access outside derived class

    p1.set_age(24);                                //public     -> have acess outside derived class
    cout << p1 << endl;                            //can access through base class function
    cout << endl;

    //2. Protected inheritance
    Engineer p2("Civil");
  //p1.first_name = "Alex";                        //protected -> do not have access outside derived class
  //p1.last_name = "Christopher";     ->error      //protected -> do not have access outside derived class

  //p1.age = 26;                                   //private   -> do not have access outside derived class

  //p2.set_age(33);                   ->error      //protected -> do not have access outside derived class
    p2.set_engineer_age(36);
    cout << p2.get_engineer_age();                 // can access through derived class function only
    cout << endl;

    return 0;

}

ostream& operator<<(ostream& out, const Player& player){
    out << "Player : [ game : " << player.m_game
        << " , name : " << player.get_first_name()
        << " " << player.get_last_name()
        << " , age: " << player.get_age() << "]";
    return out;
}

Person::Person(string_view first_name_param, string_view last_name_param, int age_param){
    first_name = first_name_param;
    last_name = last_name_param;
    age = age_param;
}

Person::~Person(){

}

Player::Player(string_view game_param){ 
    m_game = game_param; 
    first_name = "John";   
    last_name = "Snow";
}

Player::~Player(){

}

Engineer::Engineer(string_view major_param){
    m_major = major_param;
}

Engineer::~Engineer(){

}