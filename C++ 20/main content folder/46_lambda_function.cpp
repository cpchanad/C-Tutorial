#include <iostream>
#include <string>
using namespace std;

//Lambda function
//A mechanism to set up anonymous function without name

/*
Lambda function signature:
[capture list] (parameters) -> return type{            //return type are optional
    --fucntion body--
};
*/

//declare and define lambda function
auto func = [](){
    cout << "Hello World" << endl;
};  //add semi-colon ';'

auto test = [](double a, double b)->int{
    return a + b;
};

int main(){

    // call defined lambda function
    func();

    // call lambda function directly after definition
    [](){
        cout << "Hello. This is more direct." << endl;
    }();  // add () in the end just like other function

    // lambda function that take parameters
    [](double a, double b){
        cout << "a + b = " << a + b << endl;
    }(12.5,26.4);

    //Lamda function that return something
    auto result = [](double a, double b){
        return a + b;
    }(12.8,82.4);
    cout << result << endl;

    //Print result directly
    cout << "result: " << [](double a, double b){
        return a + b;
    }(53.1,89.4) << endl;

    //Specify return type explicitly
    auto result_2 = [](double a, double b)->double{
        return a + b;
    }(24.5,97.3);
    cout << result_2 << endl;
    cout << endl;
    
    //lambda function declare&define outside can re-call multiple times
    //call function and directly print it out
    cout << test(3.14,9.45) << endl;
    cout << test(4.6,9.7) << endl;
    cout << endl;

    //lambda function declare&define inside can re-call multiple times
    auto result_3 = [](double a, double b){
        return a + b;
    };
    cout << result_3(23.2,39.9) << endl;
    cout << result_3(3.2,3.9) << endl;
    cout << endl;

    //lambda function declare&called inside can only use one time
    auto result_4 = [](double a, double b){
        return a + b;
    }(14.8,32.4);
    cout << result_4 << endl;   //return value is store in variable

    return 0;

}