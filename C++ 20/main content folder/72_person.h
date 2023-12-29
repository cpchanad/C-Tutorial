#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>
using namespace std;

class Person{

    friend ostream& operator<<(ostream& out, const Person& person);
    
    public:

        Person() = default;
        Person(string_view fullname, int age, string_view address);
        ~Person();

        //Getter
        string get_fullname() const{
            return m_fullname;
        }
        int get_age() const{
            return m_age;
        }
        string get_address() const{
            return m_address;
        }

        //Setter
        void set_address(string_view address){
            m_address = address;
        }

    public:
        string m_fullname {"None"};
    protected:
        int m_age {0};
    private:
        string m_address {"None"};
};

#endif