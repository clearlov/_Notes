class Copper
{
public:
	void smelt(){ cout << "smelt" << endl; }
	virtual void forge(){ cout << "forge" << endl; }
};
class Brass :   public Copper, 
                protected std::string, 
                private std::valarray<int>
{
public:
    using std::valarray<int>::min;
	void smelt(){ cout << "re-smelt" << endl; }
	virtual void forge(){ cout << "re-forge" << endl; }
};




Copper * copper = new Brass();
copper->smelt();   // smelt
copper->forge();   // re-smelt



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