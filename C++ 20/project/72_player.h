#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <string_view>
using namespace std;

#include "72_person.h"

//Player will do public inheritance from Person
class Player: public Person{

    friend ostream& operator<<(ostream& out, const Player& player);

    public:
    
        Player();
        Player(int career_start_year, double salary, int health_factor);
        ~Player();

        void play(){
            m_fullname = "John Snow";                 // OK    because 'public' to base class allow access within derived class
            m_age = 30;                               // OK    because 'protected' to base class allow access within derived class
          //m_address = "387 Red Dragon Street"      -> error  because 'private' to base class not allow access within derived class
            this->set_address("387 Red Dragon Street");
        }
    
    private:
        int m_career_start_year {0};
        double m_salary {0.0};
        int m_health_factor {0};

};

#endif