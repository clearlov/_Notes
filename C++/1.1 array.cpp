int a1[2];   // declaration, a1={1,2} or a1[0]=1; a1[1]=2;

int a2[2] = {1,2};  //initializing arrays
    
// same sa
int a2[] = {1,2};
//same as 
int a2[]{1,2};



int * c1 = new int[2]; // * c1 = {1, 2};  or c1[0] = 1; c2[1] = 2;
delete []c1;  // delete pointer
    
int * c2 = a2;   // c2[0] equals *c2, the first element of an array
int * c3 = &a2[0];  // the address of this array, equals &a2
int x = * (&a2);  // * (&a2[0])  == a2[0]

int * c4 = a2 + 1;  // the right value must be address, a2 = &a2 = &a2[0]
// it's &a2[0] + 1 =  &a2[1]
int y = * (a2 + 1);  // a2[1]

    
const int a8[2];   // declaration, a8={1,2};  CAN'T a8[0]=1;
const int * c8 = new int[2]; // *c8 = {1, 2}; CAN'T c8[0]=1;

/************************* valarray ****************************/
#include <valarray>
typedef std::valarray<int> ArrayInt;
int v0[3] = {10, 20, 30};
ArrayInt v1; // size 0 array
ArrayInt v2(2);  // size 2 array
ArrayInt v3(0, 2);  // {0, 0}, size 2, and initializing each to 0
ArrayInt v4(v0, 2);  // {10, 20}

std::valarray<int, 1> arr;

for(int i : a2) cout << i <<endl;  // will output 1, 2
    
    
/************************* array ****************************/    
#include <array>

std::array<int, 2> a;   // 2 ints
a = {2, 4};
    
    
/************************* char array **********************/
// a char array is end with \0
    
char fetal[] = {'f', 'e', '\0', 't', 'a', 'l'};
// strlen(fetal)  is 2  ==> "fe", ignore every chars after '\0'
char fetal = "fe\0tal";  // strlen(fetal) is 2
    
    