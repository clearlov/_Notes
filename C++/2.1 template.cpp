/**
 * 
 */
template <typename T1, typename T2>
class Precede{
	public:
		T1 precedence(T1 x){return x;}
		void precedent(T2 z);
};
template <typename T1, typename T2>
void Precede<T1, T2>::precedent(T2 z){
	cout << "precedent: " << z << endl;
}

template <typename T1, typename T2>
void convey(Precede<T1,T2> p){
	cout << p.precedence(100) << endl;
}


Precede<int, const char *> p;
const char * precession = "Vince-Well";
p.precedent(precession);
 
 
 

/* You should use templates if you need functions that apply the same algorithm to a variety of
types. If you aren’t concerned with backward compatibility and can put up with the effort of
typing a longer word, you can use the keyword "typename" rather than "class" when you
declare type parameters. */

template <typename T> void func(T &a);   // implicit instantiation


/* Originally,using implicit instantiation was the only way the compiler generated func-
tion definitions from templates,but now C++ allows for explicit instantiation.That means
you can instruct the compiler to create a particular instantiation—for example,
Swap<int>()—directly.The syntax is to declare the particular variety you want,using the
<>notation to indicate the type and prefixing the declaration with the keyword
template: */

template void Swap<int>(int, int);  // explicit instantiation
template <> void Swap<int>(int &, int &);  // explicit specialization
template <> void Swap(int &, int &);       // explicit specialization

/* The difference is that these last two declarations mean “Don’t use the Swap() template
to generate a function definition.Instead,use a separate,specialized function definition
explicitly defined for the int type.”These prototypes have to be coupled with their own
function definitions.The explicit specialization declaration has <> after the keyword tem-
plate,whereas the explicit instantiation omits the <>.

It is an error to try to use both an explicit instantiation and an explicit specia
same type(s) in the same file,or,more generally,the same translation unit. */

template <class T>
T Add(T a, T b)    // pass by value
{
return a + b;
}
...
int m = 6;
double x = 10.2;
cout << Add<double>(x, m) << endl;  // explicit instantiation

/* The template would fail to match the function call Add(x, m)because the te
expects both function arguments to be of the same type.But using Add<double>
forces the type doubleinstantiation,and the argument mis type cast to type doub
match the second parameter of the Add<double>(double, double)function. */


void Swap(T &a, T &b); 

/* This generates an explicit instantiation for type double.Unfortunately,in this case,the
code won’t work because the first formal parameter,being type double &,can’t refer to
the type int variable m.
Implicit instantiations,explicit instantiations,and explicit specializations collectively are
termed specializations.What they all have in common is that they represent a function defi-
nition that uses specific types rather than one that is a generic description.
The addition of the explicit instantiation led to the new syntax of using template and
template <>prefixes in declarations to distinguish between the explicit instantiation and
the explicit specialization.As in many other cases,the cost of doing more is more syntax
rules.The following fragment summarizes these concepts: */