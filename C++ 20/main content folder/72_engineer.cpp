#include <iostream>

#include "72_person.h"
#include "72_engineer.h"

ostream& operator<<(ostream& out, const Engineer& operand){
    out << "Engineer [Full name : " << operand.get_fullname() <<
                         ", Age : " << operand.get_age() <<
                     ", Address : " << operand.get_address() <<
              ", Contract count : " << operand.contract_count << " ]";
    return out;
}

Engineer::Engineer(){

}

Engineer::Engineer(int c_count){
    contract_count = c_count;
}

Engineer::~Engineer(){

}