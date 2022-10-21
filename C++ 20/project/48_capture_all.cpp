#include <iostream>
#include <string>
using namespace std;

int main(){

    //Capture all
    //Capturing everything

    //using a equal sign (=) to capture everything by value
    int c {42};

    auto func = [=](){
        cout << "In: " << c << endl;
    };

    for(size_t i {}; i < 5; ++i){
        cout << "Out: " << c << endl;
        func();
        c++;
    }
    cout << endl;

    // using a and sign (&) to capture everything by reference
    double d {42.5};

    auto func2 = [&](){
        cout << "In: " << c << endl;
        cout << "In: " << d << endl;
    };

    for(size_t i {}; i < 5; ++i){
        cout << "Out: " << c << endl;
        cout << "Out: " << d << endl;
        func2();
        c++;
        d += 0.5;
    }

    return 0;

}