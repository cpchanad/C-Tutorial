#include <iostream>
#include <string>
using namespace std;

int main(){

    //reassignment of stack address to active dynamic address pointer
    int *p_number {new int {12}}; //dynamic address

    cout << p_number << endl;
    cout << endl;
    //should delete p_number first and then reassign
    delete p_number;
    p_number = nullptr;

    int number {55};              //stack address

    p_number = &number;           //dynamic address lose by assigning a stack address to a dynamic address
                                  //no way to release the dynamic memory anymore
                                  //memory leaked (OS can't use that memory anymore)

    cout << p_number << endl;

    p_number = nullptr;

    //if memory leak occur, program that keep running for a lot time might run out of memroy
    //and it will terminate your program if heap run out of space
    
    return 0;

}