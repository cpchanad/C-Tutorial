//This bring the iostream library
#include <iostream>
#include <string>
#include <limits>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){
    // show the limit of different type
    cout << "short int:" << endl;
    cout << "max: " << numeric_limits<short int>::max() << endl;
    cout << "min: " << numeric_limits<short int>::min() << endl;
    cout << endl;

    cout << "unsigned int:" << endl;
    cout << "max: " << numeric_limits<unsigned int>::max() << endl;
    cout << "min: " << numeric_limits<unsigned int>::min() << endl;
    cout << endl;

    cout << "float:" << endl;
    cout << "max: " << numeric_limits<float>::max() << endl;
    cout << "min: " << numeric_limits<float>::min() << endl;
    cout << "lowest: " << numeric_limits<float>::lowest() << endl;
    cout << endl;

    cout << "double:" << endl;
    cout << "max: " << numeric_limits<double>::max() << endl;
    cout << "min: " << numeric_limits<double>::min() << endl;
    cout << "lowest: " << numeric_limits<double>::lowest() << endl;
    cout << endl;

    cout << "long double:" << endl;
    cout << "max: " << numeric_limits<long double>::max() << endl;
    cout << "min: " << numeric_limits<long double>::min() << endl;
    cout << "lowest: " << numeric_limits<long double>::lowest() << endl;

    return 0;

}