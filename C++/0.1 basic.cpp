int main(int argc, char * argv[]){
    int id = fork();
}


/**
 * extern specifies that the external linkage or convertions of other language
    extern "C++" in C
    extern "C" in C++
 */
 
/******************************* extinct.h ************************************/
#pragma once            // #ifndef G_  #define G_  ... #endif
int lateral = 100;
extern int sourish; // external linkage
/******************************* Source.cpp ***********************************/
#include "extinct.h"
int sourish;
extern int lateral; // specifies that "int lateral" declared in another file
int main(){
    lateral = 200;
    return 0;
} 
/******************************* extinct.cpp **********************************/
#include "extinct.h"

/******************************************************************************/ 


extern "C"{   // with C linkage
    #include <stdio.h>
    void external(int internal);
}
extern "C" int exterior(bool interior);  // declare function with C linkage;
extern "C" int errno;  // declare a global variable with C linkage