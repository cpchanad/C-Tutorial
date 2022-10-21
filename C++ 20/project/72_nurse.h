#ifndef NURSE_H
#define NURSE_H

#include <iostream>
#include <string>
#include <string_view>
using namespace std;

#include "72_person.h"

//Nurse will do protected inheritance
class Nurse: protected Person{

    friend ostream& operator<<(ostream& out, const Nurse& operand);

    public:
    
        Nurse();
        Nurse(int pc_id);
        ~Nurse();

        void treat_unwell_person(){
            m_fullname = "Violet Evergarden";         // OK    because 'protected' to nurse class allow access within derived class
            m_age = 22;                               // OK    because 'protected' to base class allow access within derived class
          //m_address = "12 Yellow Street"           -> error  because 'private' to base class not allow access within derived class
            this->set_address("12 Yellow Street");
        }

    private:

        int practice_certificate_id {0};

};

class intern_nurse: public Nurse{

    friend ostream& operator<<(ostream& out, const intern_nurse& operand){
        out << "Intern Nurse  [Full name : " << operand.get_fullname() <<
                                  ", Age : " << operand.get_age() <<
                              ", Address : " << operand.get_address() <<
                            ", Intern ID : " << operand.intern_id << " ]";
        return out;
    }

    public:

        intern_nurse() = default;
        ~intern_nurse(){
        }

        void treat_practice(){
            m_fullname = "Intern";                     // OK    because 'protected' to nurse class allow access within derived class
            m_age = 19;                                // OK    because 'protected' to base class allow access within derived derived class
          //m_address = "14 Black Alpha way";          -> error  because 'private' to base class not allow access within derived derived class
          this->set_address("14 Black Alpha way");     // OK    because 'protected' to nurse class allow access within derived class
        }

    private:

        int intern_id {0};
};

#endif