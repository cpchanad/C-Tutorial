#ifndef ENGINEER_H
#define ENGINEER_H

#include <iostream>
#include <string>
#include <string_view>
using namespace std;

#include "72_person.h"

//Engineer is doing private inheritance
class Engineer: private Person{

    friend ostream& operator<<(ostream& out, const Engineer& operand);

    public:

        Engineer();
        Engineer(int c_count);
        ~Engineer();

        void build_something(){
            m_fullname = "Adam Oiliver";           // OK    because 'private' to engineer class allow access within derived class
            m_age = 50;                            // OK    because 'private' to engineer class allow access within derived class
          //m_address = "789 Shaky Road"          -> error  because 'private' to base class not allow access within derived class
            this->set_address("789 Shaky Road");
        }

        //Getter
        string get_engineer_name() const{
            return this->get_fullname();
        }
        int get_engineer_age() const{
            return this->get_age();
        }
        string get_engineer_address() const{
            return this->get_address();
        }


    private:

        int contract_count {0};

};

class civil_engineer: public Engineer{

    friend ostream& operator<<(ostream& out, const civil_engineer& operand){
    /*
        out << "Civil Enginner  [Full name : " << operand.get_fullname() <<
                                    ", Age : " << operand.get_age() <<                     -> error   because 'private' to engineer class not allow access within derived class 
                                ", Address : " << operand.get_address() <<
                           ", Project Done : " << operand.no_of_project << " ]";
    */
        out << "Civil Enginner  [Full name : " << operand.get_engineer_name() <<
                                    ", Age : " << operand.get_engineer_age() <<
                                ", Address : " << operand.get_engineer_address() <<
                           ", Project Done : " << operand.no_of_project << " ]";
        return out;
    }

    public:

        civil_engineer() = default;
        ~civil_engineer(){
        }

        void build_bridge(){
          //m_fullname = "Bobby";            -> error  because 'private' to engineer class not allow access within derived class
          //m_age = 45;                      -> error  because 'private' to engineer class not allow access within derived class
          //m_address = "";                  -> error  because 'private' to base class not allow access within derived derived class
          //this->set_address("42 Wary Street");   -> error  because 'private' to engineer class not allow access within derived class
        }

    private:

        int no_of_project {0};

};

#endif