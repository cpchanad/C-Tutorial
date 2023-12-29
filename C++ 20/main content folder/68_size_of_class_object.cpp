#include <iostream>
#include <string>
using namespace std;

//size of class object

class Wrapper{
    //function are not accounted for the size of a class object, they are stored in other location
    public:
        string get_name();
        void do_something(){
        }
        void print_info(){
            cout << "var1: " << m_var1 << endl;
            cout << "var2: " << m_var2 << endl;
            cout << "name: " << m_name << endl;
        }
    //size of class object = sum of all member variables in term of size (roughly)
    private:
        int m_var1 {};              //4 byte in memory
        int m_var2 {};              //4 byte in memory
        int* p_var3 {};             //pointer are 4 byte in memory
        string m_name {"Haliluya"}; //unspecified byte in memory, stored as const char pointer by default
};                                  //add up all member variables size to get object size (not always the case)

    //The reason not always the sum of size of member variables:
    //boundary alignment
    //might have gaps between memory if multiple types of member variables exist
    //total memory are slightly off due to this phenomenon

int main(){

    Wrapper wp1;
    cout << "size of var1: " << sizeof(int) << endl;
    cout << "size of var2: " << sizeof(int) << endl;
    cout << "size of var3: " << sizeof(int*) << endl;
    cout << "size of name: " << sizeof(wp1.get_name()) << endl;      //string are stored as a pointer (char pointer)
    cout << endl;                                                    //i.e. an address (as a pointer variables)
    cout << "size of a class object is" << endl;                     //no matter how long the string is, still the same
    cout << "4 + 4 + 4 + " << sizeof(wp1.get_name()) << " = " << sizeof(wp1) << endl;     //= 4 + 4 + sizeof(string)

    cout << endl;
    cout << "*size of <string>: " << sizeof(string) << endl;

    return 0;

}

string Wrapper::get_name(){
    return m_name;
}