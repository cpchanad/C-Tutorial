#include <iostream>

#include "72_person.h"
#include "72_nurse.h"

ostream& operator<<(ostream& out, const Nurse& operand){
    out << "Nurse  [Full name : " << operand.get_fullname() <<
                       ", Age : " << operand.get_age() <<
                   ", Address : " << operand.get_address() <<
   ", Practice Certificate ID : " << operand.practice_certificate_id << " ]";
    return out;
}

Nurse::Nurse(){

}

Nurse::Nurse(int pc_id){
    practice_certificate_id = pc_id;
}

Nurse::~Nurse(){

}