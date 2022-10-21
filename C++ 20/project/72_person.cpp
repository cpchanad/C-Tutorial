#include <iostream>

#include "72_person.h"

ostream& operator<<(ostream& out, const Person& person){
    out << "Person [Full name : " << person.get_fullname() <<
                       ", Age : " << person.get_age() <<
                   ", Address : " << person.get_address() << " ]";
    return out;
}

Person::Person(string_view fullname, int age, string_view address){
    m_fullname = fullname;
    m_age = age;
    m_address = address;
}

Person::~Person(){

}