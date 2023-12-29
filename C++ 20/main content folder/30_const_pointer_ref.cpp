#include <iostream>
#include <string>
using namespace std;

int main(){

    int age {27};
    const int &ref_age {age};

    cout << age << endl;
    cout << ref_age << endl;

    //ref_age = 28;   -> error because reference is constant
    cout << endl;

    //The first 'const' indicate constant data
    //The second 'const' indicate constant pointer
    const int *const p_age {&age};

    cout << *p_age << endl;

    //*p_age = 28;    -> error becuase pointer's data is constant
    cout << endl;

    int age_2 {22};
    int age_3 {23};
    const int *p_age_2 {&age_2};  //can make data const but pointer not const or vice versa

    cout << *p_age_2 << endl;
    //*p_age_2 = 33;  -> error
    p_age_2 = &age_3;
    cout << *p_age_2 << endl;
    //*p_age_2 = 33;  -> error

    age_3 = 33;   //but can change the original because original is not const
    cout << *p_age_2 << endl;

    return 0;

}