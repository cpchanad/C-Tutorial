#include <iostream>
#include <string>
using namespace std;

//Function Output
//make output argument 'reference' or 'pointer'
//when the output parameter pass into the function, change inside the function will affect the outside value
//Reference are preferred in C++

//input can be passed by value, it will make a copy which use another memory
//Using reference will not induce addition memory usage
void max_str(const string &input1, const string &input2, string &output){  //output no const -> can be modified
    if(input1 > input2){                                                   //reference output -> change made inside function will affect outside
        output = input1;
    }else{
        output = input2;
    }
}

void max_int(int input1, int input2, int &output){   //output is a reference
    if(input1 > input2){
        output = input1;
    }else{
        output = input2;
    }
}

void max_double(double input1, double input2, double *output){   //output is a pointer
    if(input1 > input2){
        *output = input1;
    }else{
        *output = input2;
    }
}

int main(){

    string out_str;
    string a {"This is a test sentence."};
    string b {"This is another test sentence"};

    max_str(a, b, out_str);
    cout << out_str << endl;
    
    int out_int;
    int c {48};
    int d {32};

    max_int(c, d, out_int);
    cout << out_int << endl;

    double out_double;
    double e {28.24};
    double f {39.75};

    max_double(e, f, &out_double);
    cout << out_double << endl;

    return 0;

}