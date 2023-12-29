#include <iostream>
#include <string>
#include <string_view>
using namespace std;

//Copy constructors with inheritance
class Person{
    friend ostream& operator<<(ostream& out, const Person& person){
        out << "Person [Full name : " << person.get_fullname() <<
                           ", Age : " << person.get_age() <<
                       ", Address : " << person.get_address() << " ]";
        return out;
    }
    public:
        Person(){ cout << "Default constructor called for 'Person' class..." << endl; }
        Person(string_view name, int age, string_view address)
            :m_name(name), m_age(age), m_address(address)
            {
                cout << "Custom contructor called for 'Person' class..." << endl;
            }
        //Custom Copy Constructor (if not created, compiler will construct one by default)
        Person(const Person& source)
            :m_name(source.m_name), m_age(source.m_age), m_address(source.m_address)
            {
                cout << "Copy constructor called for 'Person' class..." << endl;
            }
        ~Person(){}
        string get_fullname() const{
            return m_name;
        }
        int get_age() const{
            return m_age;
        }
        string get_address() const{
            return m_address;
        }
    private:
        string m_name {"None"};
        int m_age {0};
        string m_address {"None"};
};

class Engineer: public Person{
    friend ostream& operator<<(ostream& out, const Engineer& openrad){
        out << "Engineer [Full name : " << openrad.get_fullname() <<
                             ", Age : " << openrad.get_age() <<
                         ", Address : " << openrad.get_address() << 
                  ", Contract Count : " << openrad.get_contract_count() << " ]";
        return out;        
    }
    public:
        Engineer(){ cout << "Default constructor called for 'Engineer' class..." << endl; }
        Engineer(string_view name, int age, string_view address, int c_count)
            :Person(name,age,address), contract_count(c_count)
            {
                cout << "Custom contructor called for 'Engineer' class..." << endl;
            }
        //Custom Copy Constructor (if not created, compiler will construct one by default)
        Engineer(const Engineer& source)
            :Person(source), contract_count(source.contract_count)    //Reuse copy constructor in Person class
            {
                cout << "Copy constructor called for 'Engineer' class..." << endl;
            }
        ~Engineer(){}
        int get_contract_count() const{
            return contract_count;
        }
    private:
        int contract_count {0};
};

class CivilEngineer: public Engineer{
    friend ostream& operator<<(ostream& out, const CivilEngineer& openrad){
        out << "Civil Engineer [Full name : " << openrad.get_fullname() <<
                                   ", Age : " << openrad.get_age() <<
                               ", Address : " << openrad.get_address() << 
                        ", Contract Count : " << openrad.get_contract_count() <<
                          ", Specialities : " << openrad.m_strength << " ]";
        return out;        
    }
    public:
        CivilEngineer(){ cout << "Default constructor called for 'Civil Engineer' class..." << endl; }
        CivilEngineer(string_view name, int age, string_view address, int c_count, string_view strength)
            :Engineer(name,age,address,c_count), m_strength(strength)
        {
            cout << "Custom contructor called for 'Civil Engineer' class..." << endl;
        }
        //Custom Copy Constructor (if not created, compiler will construct one by default)
        CivilEngineer(const CivilEngineer& source)
            :Engineer(source), m_strength(source.m_strength)    //Reuse copy constructor in Engineer class
            {
                cout << "Copy constructor called for 'Civil Engineer' class..." << endl;
            }
        ~CivilEngineer(){}
    private:
        string m_strength {"None"};
};

int main(){

    Engineer eng1("Daniel Wan",41,"25 Green Sky Street",12);
    cout << eng1 << endl;

    //Copy Constructor called
    Engineer eng2(eng1);  
    cout << eng2 << endl;

    cout << endl;

    CivilEngineer p1("Alex Christopher",23,"198 Red Wine Street",20,"Bridge Building");
    cout << p1 << endl;

    //Copy Constructor called
    CivilEngineer p2(p1);
    cout << p2 << endl;

    return 0;

}