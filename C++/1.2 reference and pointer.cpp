/* (1)指针：指针是一个变量，只不过这个变量存储的是一个地址，指向内存的一个存储单元；而引用跟原来的变量实质上是同一个东西，只不过是原变量的一个别名而已。
(2)可以有const指针，但是没有const引用；

(3)指针可以有多级，但是引用只能是一级（int **p；合法 而 int &&a是不合法的）

(4)指针的值可以为空，但是引用的值不能为NULL，并且引用在定义的时候必须初始化；

(5)指针的值在初始化后可以改变，即指向其它的存储单元，而引用在进行初始化后就不会再改变了。

(6)"sizeof引用"得到的是所指向的变量(对象)的大小，而"sizeof指针"得到的是指针本身的大小；

(7)指针和引用的自增(++)运算意义不一样； */

/*************************************************************************/
const char * sediment  = "vince";  // or char sediment[] = "vince"
const char * deposit = sediment;
const char * precipitate = "-VINCE-WELL-";
deposit = precipitate;
cout << deposit;   //  -VINCE-WELL-
cout << sediment;  // vince
/*************************************************************************/



/*************************************************************************/
short a = -1;  // the binary is :  1[ thirty zeros ]1
unsigned short b = * (short *)&a;  // 1[ thirty zeros ]1  2^15+1

/*************************************************************************/




/*************************************************************************/
int a = 100; // &a = 00CEFEC4
/**
  * cast from hex to int
  */
int b = (int) &a;  // 00CEFEC4 = 13565636  cast to int
/**
 * b is an int, but c is a pointer to int x's address
 * cast from int to (int *)
 */
int *c = (int *) b;  
int *d = (int *) 13565636;   // same as *c
/*************************************************************************/

/**
  * rats is in stack [0xFFFF] the value is 100
  */

int rats = 100;

/**
 * rodents is an reference to int rats;
 * which means rodents is an alias for rats
 * so &rodents = &rats = [0xFFFF]
 * rodents = 100;
 */
int & rodents = rats;


/**
 * pussies is a pointer to int-rats's address
 * it's a pointer, not alias. so the address is  stack [0xFFDD]
 * [0xFFDD] -> [0xFFFF]
 * so *pussies = rats, pussies = &rats
 */
int * pussies = &rats;




/**
 * &kitten = [0xFFCC]
 * [0xFFCC] -> [0xFFDD] -> [0xFFFF]
 */
int * kitten = pussies;

/**
 * &pony = [0xFFBB]
 * [0xFFBB] -> [0xFFFF] => {0x0000}
 */
int * pony = &rodents;



/**
 * reset [0xFFFF] 's value 200
 * so *pussies = 200 
 * so *kitten = 200
 * so rodents = 200
 */
rats = 200;

/**
 * puppy is a pointer to a int, it points to pony 
 * so *puppy = 200
 * [0xFFAA] -> [0xFFBB] -> [0xFFFF]
 */
int * puppy;
puppy = pony;  
// same as 
int * puppy2 = (int *) pony;  // cast pony to address (actually it is)

int * pointy = (int *) 10000;  // cast 10000 to address


/**
 * set address pony ([0xFFFF]) 's value to 300
 * [0xFFBB] -> [0xFFFF]
 */
*pony = 300;


int * chick;   // CAN'T int * chick = 10; or int * chick; * chick=10;
chick = (int*)malloc(sizeof(int));  // sizeof(int) = 4
// malloc(4) is void *, it's a address like
*chick = 10;

int * pi = new (std::nothrow) int;



// int * pussies = rats;  it's fatal error

/**
 * squirrels is a pointer
 * squirrels equals "squirrels"
 * pointer *squirrels equal "s"
 * 
 */
char * squirrels = "squirrels";

    
const char * lamb = "sheep"; //lamb is a pointer to const char same as char const * lamb; because there isn't const * in C++;
lamb = "another";  // okay

const int n=2; // same as int const n=2; you can exchange const's place with other types
    
  

char * const piglet = "piggy";  // piglet is a const pointer to char
// CAN'T piglet = "another";  

char ** pp;  // pointer to pointer to char  
    
    
/* In this context, & is not the address operator. Instead, it serves as part of the type identi-fier. Just as char * in a declaration means pointer-to-char, int & means reference-to-int.The reference declaration allows you to use rats and rodents interchangeably; both refer to the same value and the same memory location. Listing 8.2 illustrates the truth of this claim.

Then you could use the expressions rodents and*prats interchangeably with rats and use the expressions &rodents and prats interchangeably with &rats.From this standpoint,a reference looks a lot like a pointer in disguised notation in which the * dereferencing operator is understood implicitly.And,in fact,that’s more or less what a reference is.But there are differences besides those of notation.
For one,it is necessary to initialize the reference when you declare it; you can’t declare the reference and then assign it a value later the way you can with a pointer: */
int rat;
int & rodent;
rodent = rat;   // No, you can't do this. You should initialize a reference variable when you declare it.

A reference is rather like a const pointer; you have to initialize it when you create it, and when a reference pledges its allegiance to a particular variable, it sticks to its pledge.



int rats = 101;  // address 0x0066ff88
int & rodents = rats;  // reference, rodents equal rats, and &rodents equals &rats (0x0065fd44)
int bunnies = 50;  // address 0x00556677
rodents = bunnies;  // & rodents is a reference to rats, they share the same address(0x0065fd44)
cout << rats << endl;  // print 50



int rats = 101;   // address 0x0066ff88
int * pussies = &rats;    // *pussies is a pointer to address 0x0066ff88, *pussies equals rats
int & rodents = *pussies;  // reference to *pussies (address is 0x0066ff88)
int bunnies = 50;  // adress 0x00556677
pussies = &bunnies;  // pointer to new address 0x00556677

cout << *pussies << endl;  // 50
cout << rats << endl;   // 101
cout << rodents << endl;  // a reference to 0x0066ff88, 101



/*********************  && **************************/

int && dinosaur = 100; // dinosaur = 100, &dinosaur is address
int && fossil = 100 + 100;









