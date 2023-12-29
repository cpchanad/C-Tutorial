#include <iostream>
#include <string>
using namespace std;

int main(){
    //handling the problem method
    
    //exception mechanism
    try                                      //try block
    {
        int *test {new int[1000000000000000000]};
    }
    catch(exception& ex)                     //if the code in try block fail, excute exception
    {
        cerr << "Cought exception ourselves: " << ex.what() << endl;
    }
    // heap memory run out and error


    //std::nothrow option
    int *test_2 {new(nothrow) int[1000000000000000000]};  //if the code failed, tell the system no throw an exception
                                                          //return nullptr instead
    if(test_2 == nullptr){
        cout << "Memory allocation failed" << endl;
    }else{
        cout << "Memory allocation succeeded" << endl;
    }
    // heap memory run out and error

    return 0;

}