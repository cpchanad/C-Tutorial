#include "69_person.h"
#include "69_player.h"

Player::Player(string_view game_param, string_view first_name_param, string_view last_name_param){
    m_game = game_param;
    this->set_first_name(first_name_param);
    this->set_last_name(last_name_param);
    /*
    first_name = "sth"  -> error
    last_name = "sth"   -> error because player(pulic inheritance) don't have access to base class private variables
    */
}

ostream& operator<<(ostream& out, const Player& player){
    out << "Player : [ game : " << player.m_game
        << " , name : " << player.get_first_name()
        << " " << player.get_last_name() << "]";
    /*
    out << player.first_name  -> error 
        << player.last_name   -> error  because player(pulic inheritance) don't have access to base class private variables
    */
    return out;
}

Player::~Player(){

}