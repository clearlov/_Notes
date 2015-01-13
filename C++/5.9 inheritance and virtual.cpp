/**
 * DerivedClass: public B1Class ==>
 * DerivedClass: private B1Class ==> public/protected/private turns to private
 * DerivedClass: protected B1Class ==> public/protected turns to protected
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
 
 
class Remembrance : private Recollect,    // private inherit
					protected std::string, 
					private std::valarray<int>
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
 
 
/**
 * static, inline and construct function can't be a virtual function
 * destruct function can be a virtual function
 */ 
 

class B{
	public:
	const char *polymer;
	B(const char *p="p-B"):polymer(p){}
	void polymorphism(){
		cout << "p()-B" << endl;
	}
	virtual void polymorphism(const char *p){
		cout << "p(\"" << p << "\")-B" << endl;
	}
	virtual ~B(){}
};

class D: public B{
	public:
	D(const char*p = "p-D"):polymer(p){}
	void polymorphism(){
		cout << "p()-D" << endl;
	}
	virtual void polymorphism(const char *P){
		cout << "p(\"" << p << "\")-D" << endl;
	}
	virtual ~D(){delete polymer;}
} 
					
/*************************** Base = Derived ***********************************/
D d;
/*1*/ 	B b = * dynamic_cast<B *>(&d);

/*2*/ 	B b = d;
// derived = b1;  ERROR!!!
/************************  Base points to Derived  ****************************/
D d;
/*1*/ 	B* b_p = new D();
/*2*/ 	B* b_p = dynamic_cast<B *>(&d);
/*3*/  	B* b_p = &derived;   
/************************  B=D, B ****************************/
b.polymorphism();   		b_p->polymorphism();			// p()-B
b.polymorphism("Vince"); 	b_p->polymorphism("Vince");		// p("Vince")-D


/************************  Derived points to B1  ****************************/
B b;
/*1*/	D d = * static_cast<D *>(&b);
/*1*/ 	D* d_p = static_cast<D *>(&b);
/*2*/ 	D* d_p = &b;
/*3*/	D* d_p = new B();
d.polymorphism();	d_p->polymorphism();				// p()->D
d_p->polymorphism("Vince");								// p("Vince")-D




class B{
	public:
	const char * homonym = "B";
};
class Ba: public B{
	public:
	const char * homonym = "Ba";
};
class Bb: public B{
	public:
	const char * homonym = "Bb";
};
class D: public Ba, public Bb{
	public:
	const char * homonym = "D";
	void parallel(){
		cout << Ba::homonym << endl;
		cout << Bb::homonym << endl;
		cout << this->homonym << endl;
	}
};

D d;
d.parallel();








