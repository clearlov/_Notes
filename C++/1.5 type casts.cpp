void
bool [false, true] 1-byte
short int / signed short int [-2^(2*8-1), 2^(2*8-1)] 2-bytes
long int / signed int [-2^(2*32-1), 2^(2*32-1)] 4-bytes
long long [0, 2^64] 8-bytes
char / signed char [-128, 127] 1-byte
unsigned char [0, 255] 1-byte
wchar_t [0, 2^16]
float [] 4-bytes 
double [] 8-bytes
long double 




int dint = 20;
// same as
int dint = {20};
// same as
int dint{20};

char meteor{65};
char meteor = {65};
char meteor = 'A';

char fester[] = {'f', 'e', 's', 't', 'e', 'r'};
//same as
char fester[] = "fes\0ter";
char fester[]{'f', 'e', 's', 't', 'e', 'r'};

char && robe = 'A';  // or char && robe = 65;
char && robe{'A'};
char && robe = {'A'};



const int pointed = 100;



void add(const int *p){
    int * pc;
// The const_cast operator can cast away the const from const int * p, thus allowing the compiler to accept the add statement:
    pc = const_cast<int *>(p);
    *pc ++;
}

//However, because pointed is declared as const, the compiler may protect it from any change, as is shown by the following sample output:
add(&pointed); //  pointed = 100
add(&dint);  // now dint = 21



int * cast = (int *) & pointed;  // *cast is 100

/********************** decltype ***********************/

int a = 1;
decltype(a) x;  // x is type int
decltype (a) x = a;   // x is type int, it equals 1

decltype(&a) x = &a;  // x is type &a, a pointer double *,  *x = a
decltype ((a)) x = a;   // x is type int &, it reference to a
const int & b = 1;
decltype(b) x = a;  // x is type const int &, it reference to a

decltype (a+1) y;   // y is type int


double f(int a);     // is equivalent to
auto f(int a) -> double;