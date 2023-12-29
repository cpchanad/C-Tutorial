#include <iostream>
#include <string>
using namespace std;

//inheriting base constructor

//copy constructor are not inheritable
//inherited constructor are base constructors
//if inherited, constructor are inherited with whatever access specifier they had in base class

//inherited constuctor are confusing
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
        Person(const Person& source)  //copy constructor are not inheritable
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

    //inherit base constructor: 'using' keyword
    using Person::Person;
    //which mean the following
    /*
    Engineer():Person(){}                                               //default constructor
    or
    Engineer(string_view fullname, int age, string_view address)        //custom constructor
        :Person(fullname, age, address)
        {
        }
    */
    //only person constructor are called

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
        Engineer(const Engineer& source)
            :Person(source), contract_count(source.contract_count)
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
        CivilEngineer(const CivilEngineer& source)
            :Engineer(source), m_strength(source.m_strength)
            {
                cout << "Copy constructor called for 'Civil Engineer' class..." << endl;
            }
        ~CivilEngineer(){}
    private:
        string m_strength {"None"};
};

int main(){

    //only person constructor are called & use like when declaring a person class
    Engineer p1("Alex Christopher",23,"123 Alpha Street");
    cout << p1 << endl;

    cout << endl;

    Engineer p2("Bobby shy",31,"135 Beta Street",34);
    cout << p2 << endl;

    return 0;

}