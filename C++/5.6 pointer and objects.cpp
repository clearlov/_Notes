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