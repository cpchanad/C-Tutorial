#include <iostream>
#include <string>
using namespace std;

int main(){
    //null pointer safety

    //Compact nullptr check
    int *p_number {};
    p_number = new int{12};
    if(p_number){
        cout << "p_number points to a VALID address: " << p_number << endl;
        cout << "*p_number is " << *p_number << endl;
    }else{
        cout << "p_number points to an INVALID address." << endl;
    }
    
    //okay to delete nullptr
    delete p_number;
    p_number = nullptr;

    cout << "Program end well." << endl;
    
    return 0;

}