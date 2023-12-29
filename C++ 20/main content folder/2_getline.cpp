#include <iostream>
#include <string>
using namespace std;

int addNumber(int a, int b){
    int sum = a + b;
    return sum;
}

int main(){

    int a;
    int b;
    string full_name;
    string dummy;
    int d;

    cout << "Please in put your first number: ";
    cin >> a;
    cout << "Please input your second number: ";
    cin >> b;

    cout << "Please input your full name & age: " << endl;
    getline(cin, dummy); // or cin.ignore()
    // to ignore the whitespace creted by the cin >> b above
    getline(cin, full_name);
    cin >> d;

    int sum = addNumber(a,b);

    cout << "Hello World!" << endl;
    cout << sum << endl;
    cout << "Your name is " << full_name << " and you are " << d << " year-old.";

    return 0;

}