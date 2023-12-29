#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person{

    friend ostream& operator<<(ostream& out, const Person& person);   //output info to stream

    public:
        //constructor & destructor
        Person();
        Person(string_view first_name_param, string_view last_name_param);    //pass in reference to aviod copies
        ~Person();

        //Getters
        string get_first_name() const{     //need to add 'const'
            return first_name;
        }
        string get_last_name() const{      //need to add 'const'
            return last_name;
        }

        //Setters
        void set_first_name(string_view first_name_param){
            first_name = first_name_param;
        }
        void set_last_name(string_view last_name_param){
            last_name = last_name_param;
        }

    private:
        string first_name {"None"};
        string last_name {"None"};
};

#endif