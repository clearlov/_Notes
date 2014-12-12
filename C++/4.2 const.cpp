/**
  * mutable
  * Now let¡¯s return to mutable.
  * a particular member of a structure (or class) can be altered
  * even if a particular structure (or class) variable is a const. 
  */
  
struct data
{
    char name[30];  
    mutable int accesses;
};

const data veep = {"Adam", 0};
strcpy(veep.name, "Well");   // not allowed
veep.accesses++;                  // allowed

/* 
The const qualifier to veep prevents a program from changing veep¡¯s members, but
the mutable specifier to the accesses member shields accesses from that restriction.
 */
 
/*  In C++ (but not C), the const modifier alters the default storage classes slightly.Whereas
a global variable has external linkage by default, a const global variable has internal link-
age by default.That is, C++ treats a global constdefinition, such as in the following code
fragment, as if the static specifier had been used: */
const int fingers = 10;    // same as static const int fingers = 10;
extern const int fingers = 10;  // external linkage