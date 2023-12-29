#include <iostream>                    // Format for standard headers
#include <string>
#include "39_comparisons.h"            // Format for custom header (h stand for header file)
#include "39_operations.h"             // include directive
using namespace std;

//Multiple files compilation

/*
step 1. source file -> (pre-processing) -> translation unit
source file are cpp files.
In pre-processing, all the include statement will copy the data from that file into main.cpp.
The data and all other code will be in a file called translation unit.

step 2. translation unit -> (compilation) -> object
The compiler will compile the translation unit into binary code in a object file.
1 TU convert to 1 object file.

step 3. object -> (linking) -> binary excutable
Link all the object file together to create one binary excutable.
*/

//Need a header file & a corresponding cpp file (don't need to be the same name)
//include the header file in main.cpp & place the cpp file in the same location as main.cpp

//Function cannot be implemented in the global namspace more than once.
//Otherwise, it will induce linker error.
//The linker searches for definitions in all translation unit(.cpp) file in the project.

//In this case, comparisons.h & operations.h include function declaration.
//comprarisons.cpp & operations.cpp include function definition.
//we include custom header first (i.e. #include "comprasions.h") to import data. (pre-processing stage)
//Then compiler will compile all the cpp or translation unit files. (compiling stage)
//then the linker will search for definition in all the cpp file. (linking stage)

int main(){

    int a {3};
    int b {4};

    cout << "max: " << max(a,b) << endl;
    cout << "min: " << min(a,b) << endl;
    cout << "incr_mult: " << incr_mult(a,b) << endl;

    return 0;

}