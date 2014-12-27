/**
 * int *p[n]       ==  *(p[n])
		int a = 100, b= 200;
		int *p[2] = {&a, &b};
		char *pp[] = {"Vince", "Well"};
		char **p = pp;
 * int (*p)[n]
		int a[1][2] = {{100, 200}};
		int (*p)[2] = a;
 * int (*p)()
		int origin(int x){return x;}
		int (*pfunc)(int);
		pfunc = origin;   // pfunc = &origin;
		int c = (*pfunc)(100);   // c = 100
 * int **p
 */



/**
 * int accent[3][2] = {{100,111}, {222,333}, {444,555}};
		*********** accent -> x00
		100		111		222		333		444		555
		x00		x04		x08		x12		x16		x20
 * int accent[3][2] = {*p0 -> x00, *p1 -> x08, *p2 -> x16};
		int *p0 = (int *)accent;    // -> x00
		int *p1 = p0 + 2;   // (int *)accent + 2   -> x08
		int *p2 = p1 + 2;   // -> x16
 * int accent[3][2] = {(*p)[0] -> x00, (*p)[1] -> x08, (*p)[2] -> x16 };   
		accent = x00
		(*p)[0]
 */
int accent[3][2] = {100,111,222,333,444,555};

/**
 *@ (*P) points to accent = x00, is an array with [2] elements
 * Same as:

 *@  (*p)[0] -> x00  (*p)[1] -> x02   (*p)[2] -> x04
 *@ *(*p) = (*p)[0] = *(x00) = 100
 *@ *(*p + 1)  =  
 */
int (*p)[2] = accent;





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
    
    