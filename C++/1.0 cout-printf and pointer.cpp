/*******************************************************************************
 * 
	printf()
		%p	=	address
		%d	=	digit(int)				%u	=	usigned int
		%s	=	string					%c	=	char
		%f	=	float					%e	=	float in exponential format
		%g	=	the shorter one in length between %e and %f
		%x	=	hexadecimal int			%o	=	octal int
		%lu	=	32-bit unsigned int		%llu=	64-bit unsigned int
		
 * DON'T USE "cout <<" to print address, otherwise, you'll get lost.
 * Cast "& char" to "(void *)&char" to print its address, otherwise it'll print 
	a pointer "char * rarely = &char"
	Notice: String
		cout << &char;    		===>   	printf("%s", &char);
		cout << (void *)&char 	===>	printf("%p", &char);
 */
const char* essential = "colonial";
char colony = *essential;
cout << &colony;  // c▒      @, Damn it! it's pointer-like, but not an address!
cout << (void *)&colony;  // it's the address 'c' in "colonial";

printf("&s", &colony);	// c▒      @
printf("%p", &colony);   // same as "cout << (void *)&char"

/******************************************************************************/





T *predawn = new T;

T const *predator; // const T *predator;
T *const predation;
T const *const predatory; // const T * const predatory;

const T &comlexit = *predawn;
T &erosion = *predawn;

const int exposure = 100;
const int *meteorite = & expsure;
// *meteorite = 200;   ERROR: read-only *meteorite

// int *marin = &exposure;  ERROR: const int* to int*
// int *transplant = meteorite;   ERROR: const int* to int*

printf("%p %p", &exposure, meteorite);  // 0x7f..00		0x7f..00

/**
 * const_cast from "const T*" to "T *", it works, but not suggest.
 * it'll makes const T * changeable, but const T unchangeable
 */
int *desertification = const_cast<int *>(&exposure); // not suggest
int *facial = const_cast<int *>(meteorite);  // not suggest

*desertification = 300;
cout << exposure << " " << *meteorite;  // 
*facial = 400;


/* Pointers and Objects Summary
You should note several points about using pointer s to objects (refer to Figure 12.5 for a
summary): */
//You declare a pointer to an object by using the usual notation:
String * glamour;
//You can initialize a pointer to point to an existing object:
String * first = &sayings[0];
//You can initialize a pointer by using new.The following creates a new object:
String * favorite = new String(sayings[choice]);
// Also see Figure 12.6 for a more detailed look at an example of initializing a pointer with new.
//Using new with a class invokes the appropriate class constructor to initialize the newly created object:
// invokes default constructor
String * gleep = new String;

// invokes the String(const String &) constructor
String * favorite = new String(sayings[choice]);
// You use the ->operator to access a class method via a pointer:
if (sayings[i].length() < shortest->length())
// You apply the dereferencing operator (*) to a pointer to an object to obtain an object:
if (sayings[i] < *first)    // compare object values
first = &sayings[i];   // assign object address