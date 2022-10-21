#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <string_view>
#include "69_person.h"

//class player inherited from class person
class Player: public Person{         //'public' means public inheritance - > derived classes can access public members
//                                                                           of base class, but derived class can't
//                                                                           directly access private members
    friend ostream& operator<<(ostream& out, const Player& player);

    public:
        //Constructor & destructor
        Player() = default;
        Player(string_view game_param, string_view first_name_param, string_view last_name_param); // can't access first_name & last_name
        ~Player();                                                                                 // in player class

        //Getter
        string get_game(){
            return m_game;
        }

        //Setter
        void set_game(string_view game_param){
            m_game = game_param;
        }
    private:
        string m_game {"None"};
};

#endif