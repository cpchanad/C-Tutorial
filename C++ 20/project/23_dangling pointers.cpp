#include <iostream>
#include <string>
using namespace std;

int main(){

    //dangling pointers
    //1.Uninitialized pointer
    int *p_number;                //uninitialized (contain junk address)
    //cout << *p_number << endl;   -> error: crash
    cout << endl;
    delete p_number;
    //soulution:
    //initialize pointers to nullpointer or acutal data
    //check if(p_number != nullptr){...} before using pointer
    p_number = nullptr;
    if(p_number != nullptr){
        cout << *p_number << endl;
    }else{
        cout << "No p_number pointer!" << endl;
    }
    cout << endl;

    //2.Deleted pointer
    int *p_number1 {new int {1}};
    cout << p_number1 << endl;
    cout << *p_number1 << endl;
    delete p_number1;              //resetting, p_number1 goes to junk address
    cout << p_number1 << endl;     //junk address
    cout << *p_number1 << endl;    //junk value
    cout << endl;
    //soulution:
    //set pointer to nullpointer after deleted
    //check if(p_number1 != nullptr){...} before using pointer
    p_number1 = nullptr;
    if(p_number1 != nullptr){
        cout << *p_number1 << endl;
    }else{
        cout << "No p_number1 pointer!" << endl;
    }
    cout << endl;

    //3.Multiple pointers pointing to same memory
    int *p_number2 {new int {2}};
    int *p_number3 {p_number2};
    cout << p_number2 << endl;
    cout << *p_number2 << endl;
    cout << p_number3 << endl;
    cout << *p_number3 << endl;
    delete p_number2;             //delete p_number2
    cout << p_number3 << endl;    //p_number3 points to deleted memory
    cout << *p_number3 << endl;   //crash or junk value
    //soultion:
    //make sure the owner pointer is very clear
    //check if the owner pointer is a nullpointer or not before using all other pointers
    p_number2 = nullptr;
    if(!(p_number2 == nullptr)){
        cout << *p_number3 << endl;
    }else{
        cout << "No p_number3 pointer!" << endl;
    }
    cout << endl;

    cout << "The program end well." << endl;
    
    return 0;

}