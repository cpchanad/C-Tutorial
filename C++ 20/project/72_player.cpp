#include <iostream>

#include "72_person.h"
#include "72_player.h"

ostream& operator<<(ostream& out, const Player& player){
    out << "Player [Full name : " << player.get_fullname() <<
                       ", Age : " << player.get_age() <<
                   ", Address : " << player.get_address() <<
         ", Career start year : " << player.m_career_start_year <<
                    ", Salary : " << player.m_salary <<
             ", Health factor : " << player.m_health_factor << " ]";
    return out;
}

Player::Player(){

}

Player::Player(int career_start_year, double salary, int health_factor){
    m_career_start_year = career_start_year;
    m_salary = salary;
    m_health_factor = health_factor;
}

Player::~Player(){

}