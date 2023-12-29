//This bring the iostream library
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
using namespace std;

/*
    This is a Block Comment.
*/

int main(){
    // endl or \n: make a new line
    cout << "Hello World!" << endl;
    cout << endl;

    // flush: flushes the output buffer to its final detination.
    cout << "This is a toilet flush" << endl << flush;
    cout << endl;
    // after flush, we are sure that at this line, the message has been sent
    // to the stream. This may be important in some applications.

    // setw(): adjust the field with for the item about to be printed.
    cout << setw(10) << "Manly" << setw(10) << "Chris" << setw(5) << "34" << endl;
    cout << setw(10) << "Manly" << setw(10) << "Chris" << setw(5) << "34" << endl;
    cout << setw(10) << "Manly" << setw(10) << "Chris" << setw(5) << "34" << endl;
    cout << endl;

    // right/left justified: values can be justified in their field.
    cout << left;
    cout << setw(10) << "Manly" << setw(10) << "Chris" << setw(5) << "34" << endl;
    cout << right;
    cout << setw(10) << "Manly" << setw(10) << "Chris" << setw(5) << "34" << endl;
    cout << endl;
    // internal: only the sign justified
    cout << left;
    cout << setw(10) << -123.45 << endl;
    cout << internal;
    cout << setw(10) << -123.45 << endl;
    cout << endl;

    // setfill(): fill character
    cout << left;
    cout << setfill('-');
    cout << setw(10) << "Manly" << setw(10) << "Chris" << setw(5) << "34" << endl;
    cout << endl;

    // boolalpha/noboolalpha: control bool output format
    cout << boolalpha;
    cout << true << endl;
    cout << false << endl;

    cout << noboolalpha;
    cout << true << endl;
    cout << false << endl;
    cout << endl;

    // showpos/noshowpos: show positive sign
    cout << showpos;
    cout << 34 << endl;

    cout << noshowpos;
    cout << 34 << endl;
    cout << endl;

    // dec/hex/oct: show different number system
    cout << dec << 29 << endl;
    cout << hex << 29 << endl;
    cout << oct << 29 << endl;
    cout << endl;

    // showbase: show the base for different number system
    cout << showbase;
    cout << dec << 29 << endl;
    cout << hex << 29 << endl;
    cout << oct << 29 << endl;
    cout << endl;

    // uupercase: make letter uppercase
    cout << uppercase;
    cout << hex << 29 << endl;
    cout << dec;
    cout << endl;

    // fixed & scientific: for floating point values
    double a {3.14567890123455606539};
    cout << a << endl;
    cout << scientific;
    cout << a << endl;
    cout << fixed;
    cout << a << endl;
    cout.unsetf(ios::scientific | ios::fixed); // reset to default
    cout << endl;

    // setprecision(): number of digits printed out for floating point
    cout << a << endl;
    cout << setprecision(10);
    cout << a << endl;
    cout << setprecision(20);
    cout << a << endl;
    cout << setprecision(6); // set to default

    // showpoint: for floating point values
    double i {12};
    cout << i << endl;
    cout << showpoint;
    cout << i << endl;
    cout << sizeof(i) << endl; // its a double

    return 0;

}