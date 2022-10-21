#include <iostream>
#include <string>
#include <string_view>
using namespace std;

//Custom constructors with inheritance
class Person{
    friend ostream& operator<<(ostream& out, const Person& person){
        out << "Person [Full name : " << person.get_fullname() <<
                           ", Age : " << person.get_age() <<
                       ", Address : " << person.get_address() << " ]";
        return out;
    }
    public:
        Person(){ cout << "Default constructor called for 'Person' class..." << endl; }
        //initialize with initializer list
        Person(string_view name, int age, string_view address)
            :m_name(name), m_age(age), m_address(address)       //Ps: can only initialize with own class variables
            {
                cout << "Custom contructor called for 'Person' class..." << endl;
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
        //initializer list with base class constructor
        Engineer(string_view name, int age, string_view address, int c_count)
            :Person(name,age,address), contract_count(c_count)   //can initialize with base class constructor
            {
                cout << "Custom contructor called for 'Engineer' class..." << endl;
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
        //initializer list with upstream class constructor
        CivilEngineer(string_view name, int age, string_view address, int c_count, string_view strength)
            :Engineer(name,age,address,c_count), m_strength(strength)  //can initialize with upstream class constructor
        {
            cout << "Custom contructor called for 'Civil Engineer' class..." << endl;
        }
        ~CivilEngineer(){}
    private:
        string m_strength {"None"};
};

int main(){

    //custom constructor are called and passing args to other sub-constructor
    Person p1("Alex Christopher",23,"18 Blue Sky Street");
    cout << p1 << endl;
    cout << endl;

    Engineer p2("Bobby Wan",45,"187 Yellow Axe Street",10);
    cout << p2 << endl;
    cout << endl;

    CivilEngineer p3("John Snow",30,"98 Red Dragon Street",5,"Brigde Building");
    cout << p3 << endl;
    cout << endl;

    //default constructor are called if no args passing in
    CivilEngineer p4;
    cout << p4 << endl;

    return 0;

}