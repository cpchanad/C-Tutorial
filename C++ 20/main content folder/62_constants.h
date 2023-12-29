#ifndef CONSTANTS_H                //if constants_H not defined, execute the code within the body 
#define CONSTANTS_H                //if constants_H is defined, skip it
                                   //i.e. this file is going to only excute one time only
#define PI 3.14159265              //     even if 'constant.h' is included more than two time
                                   //this act as an include guard to prevent re-definition of the same thing again
const double TEST {1.23};

#endif                             // '#' indicate work during pre-processing 