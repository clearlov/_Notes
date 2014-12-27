/**
 * DerivedClass: public BaseClass ==>
 * DerivedClass: private BaseClass ==> public/protected/private turns to private
 * DerivedClass: protected BaseClass ==> public/protected turns to protected
 
 ** Sequence to call BaseClass's construct/destruct function   *****************
 * 	1. Calls default BaseClass's construct method first. If there are more than 
		one BaseClass, call them via the seq. of declared.
		class Derived: public Base1, public Base2{    	// via here
			Derived(int x): Base2(x), Base1(x);       	// not here
		};
	2. Calls BaseClass's construct method in Derived Class. Call them via the 
		sequence of declared.
		class Derived{
			Base5 b5;
			Base6 b6;
		};
	3. Calls Derived class's construct method
	7. destruct of 3
	8. destruct of 2
	9. destruct of 1
	Sumary:
		class Base5{
				Base4 b4;
		};
		class Derived: public Base1, public Base2, public Base3{	// VIA HERE
				Base5 b5;  			 // not declared in inheritance
			public:
				Derived(int i):Base3(i+1), Base1(i), Base2{}   		// NOT HERE
				~Derived(){}
		};
		==> 
		Base1::Base1() --> Base2::Base2() --> Base3::Base3() 
		--> Base1::Base1(i) --> Base2::Base2(i) --> Base3::Base3(i+1)
		--> Base4::Base4() --> Base5::Base5()
		--> Derived:Derived(i)
		--> Derived::~Derived()
		--> Base5::~Base5() --> Base4::~Base4()
		--> Base3::~Base3() --> Base2::~Base2() --> Base1::~Base1()
 */

class Recollect{
	private:
		int x;
	public:
		Recollect(){cout << "Recollect::Recollect()" << endl;}
		Recollect(int j){
			x=j; 
			cout << "Recoolect::Recollect(int) :" << j << endl;
		}
		void setX(int i):x(i){}
		void getX(){return x;}
		bool checkX(int y){return x == y;}
};
 
 
class Remembrance : private Recollect    // private inherit
{
	private:
	public:
		Remebrance(){cout << "Remembrance::Remembrance()" << endl;}
		Remebrance(int j): Recollect(j){}  // set its parent's construct
		Recollect::setX;    // turn private public
		Recollect::getX;
};

void recall(Recollect r){
	cout << r.getX() << endl;
}

/**
 
  Remebrance -[INHERITE]-> Recollect
  Recollect::Recollect() --> Remembrance::Remembrance()
  --> Remembrance::~Remembrance() --> Recollect::~Recollect()
 
 
 */
Remembrance r;
r.setX(100);  // ok
r.getX(); // 100
// r.checkX(100)   false,  it's a private method
 
/**
 *
 */
Remebrance r2(100);
recall(r2);
 
 
 
 

class Base
{
public:
	void smelt(){ cout << "smelt" << endl; }
	virtual void forge(){ cout << "forge" << endl; }
};

class Derived :   public Base, 
                protected std::string, 
                private std::valarray<int>
{
public:
    using std::valarray<int>::min;
	void smelt(){ cout << "re-smelt" << endl; }    // redefine smelt()
	virtual void forge(){ cout << "re-forge" << endl; }
};

/*************************** Base = Derived ***********************************/
Base base;
Derived derived;
/*1*/ 	base = * dynamic_cast<Base *>(&derived);

/*2*/ 	base = derived;
// derived = base;  ERROR!!!
/************************  Base points to Derived  ****************************/
Base* base;
Derived derived;
/*1*/ 	base = new Derived();
/*2*/ 	base = dynamic_cast<Base *>(&derived);
/*3*/  	base = &derived;   
/************************  B=D, B ****************************/
base.smelt();  // smelt
base.forge();  // re-forge


/************************  Derived points to Base  ****************************/
Base base;
Derived* derived;
/*1*/ 	derived = static_cast<Derived *>(&base);
/*2*/ 	derived = &base;
/*3*/	derived = new Base();
Derived.smelt();   // re-smelt
Derived.forge();	// re-forge


class AbstractClass
{
private:
    std:string phrase;
public:
AbstractClass(): phrase("illustrate"){}
virtual ~AbstractClass() = 0;  // pure virtual destructor
virtual void Method();
}

class Panacea : virtual public AbstractClass
{

}