#include <iostream>
#include <string>
using namespace std;

int main(){

    size_t size {10};

    //dynamically declare array and initizlized them
    double *p_salary {new double[size]};                     //contain garbage values
    int *p_student {new(nothrow) int[size] {}};              //contain 0
    double *p_score {new(nothrow) double[size] {1,2,3,4,5}}; //contain 1,2,3,4,5 and rest are 0
    //nothrow return nullptr if operator'new' failed

    //2 way to show array data: *(p_address + i) or p_address[i]
    //show address: p_address
    for(size_t i = 0; i < 10; i++){
        cout << "value: " << *(p_salary + i) << " & [" << p_salary[i] << "]" << endl;
    }                    //pointer arithemtic           array access notation
    cout << "array stored in " << p_salary << " address." << endl;
    cout << endl;

    for(size_t i = 0; i < 10; i++){
        cout << "value: " << *(p_student + i) << " & [" << p_student[i] << "]" << endl;
    }
    cout << "array stored in " << p_student << " address." << endl;
    cout << endl;

    for(size_t i = 0; i < 10; i++){
        cout << "value: " << *(p_score + i) << " & [" << p_score[i] << "]" << endl;
    }
    cout << "array stored in " << p_score << " address." << endl;
    cout << endl;
    
    // size(p_salary) won't work
    // for (auto score: p_score) won't work
    // because dynamic array are different from array
    // dynamically allocated array has decayed into a pointer
    
    //release memory (dynamic array)
    delete[] p_salary;
    p_salary = nullptr;

    delete[] p_student;
    p_student = nullptr;

    delete[] p_score;
    p_score = nullptr;

    return 0;

}