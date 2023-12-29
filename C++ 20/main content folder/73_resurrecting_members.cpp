#include <iostream>
#include <string>
#include <string_view>
using namespace std;

//Resurrecting members back in scope
//'using' keyword to resurrect (better to just use public or protected inheritance)
class Person{

    friend ostream& operator<<(ostream& out, const Person& person){
        out << "Person [Full name : " << person.get_fullname() <<
                           ", Age : " << person.get_age() <<
                       ", Address : " << person.get_address() << " ]";
        return out;
    }
    
    public:

        Person() = default;
        Person(string_view fullname, int age, string_view address){
            m_fullname = fullname;
            m_age = age;
            m_address = address;
        }
        ~Person(){}

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

class Engineer: private Person{

    friend ostream& operator<<(ostream& out, const Engineer& operand){
        out << "Engineer [Full name : " << operand.get_fullname() <<
                             ", Age : " << operand.get_age() <<
                         ", Address : " << operand.get_address() <<
                  ", Contract count : " << operand.contract_count << " ]";
        return out;        
    }

    public:

        Engineer() = default;
        Engineer(int c_count){
            contract_count = c_count;
        }
        ~Engineer(){}

        void build_something(){
            m_fullname = "Adam Oiliver";           // OK    because 'private' to engineer class
            m_age = 50;                            // OK    because 'private' to engineer class
          //m_address = "789 Shaky Road"          -> error  because 'private' to base class not
            this->set_address("789 Shaky Road");
        }

    /*
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
    */

    // above is the same as below

    //Resurrecting back to protected access:
    //change from 'private' to engineer class to 'protected' to engineer class
    protected:

        using Person::get_fullname;
        using Person::get_age;
        using Person::get_address;

    //Resurrecting back to public access:
    //change from 'private' to engineer class to 'public' to engineer class
    public:

        using Person::m_fullname;
        using Person::m_age;
      //using Person::m_address;    -> error because 'private' to base class
        using Person::set_address;

    private:

        int contract_count {0};

};

class civil_engineer: public Engineer{

    friend ostream& operator<<(ostream& out, const civil_engineer& operand){
        /*
        out << "Civil Enginner  [Full name : " << operand.get_engineer_name() <<
                                    ", Age : " << operand.get_engineer_age() <<
                                ", Address : " << operand.get_engineer_address() <<
                           ", Project Done : " << operand.no_of_project << " ]";
        */

        // above is the same as below
    
        //Resurrtected
        out << "Civil Enginner  [Full name : " << operand.get_fullname() <<
                                    ", Age : " << operand.get_age() <<                 //OK  because 'protected' to engineer class     
                                ", Address : " << operand.get_address() <<
                           ", Project Done : " << operand.no_of_project << " ]";

        return out;
    }

    public:

        civil_engineer() = default;
        ~civil_engineer(){
        }

        void build_bridge(){
          m_fullname = "Bobby";                       //OK   becuase 'public' to engineer class
          m_age = 45;                                 //OK   becuase 'public' to engineer class
        //m_address = "42 Wary Street";             -> error because 'private' to base class
          this->set_address("42 Wary Street");        //OK   becuase 'public' to engineer class
        }

    private:

        int no_of_project {0};

};

int main(){

    civil_engineer p1;
    p1.build_bridge();
    cout << p1 << endl;
    p1.m_fullname = "Alex";                         //OK   becuase 'public' to engineer class
    p1.m_age = 25;                                  //OK   becuase 'public' to engineer class
  //p1.m_address = "";                            -> error because 'private' to base class
    p1.set_address("53 Salt Street");               //OK   becuase 'public' to engineer class
    cout << p1 << endl;

    return 0;

}