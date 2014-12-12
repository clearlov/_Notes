class Copper;  //forward declaration

class Brass{
private:
    Copper * copper;
public:
    void forge(Copper & cp);

class Copper{
private:
    void smelt(){cout << "private-smelt"<<endl;}
public:
    // friend class Brass;  // use every private method;
    friend void Brass::forge(Copper & cp);  // Only forge() can access
};

// it must decelerated behind Copper's declaration
void Brass::forge(Copper &cp){
    cp.smelt();
}
    

Brass brass;
Copper cp;
brass.forge(cp);

/*****************************************************************/
    

class Anamnesis;
class Probe{
    friend void sync(Anamnesis & a, const Probe & p);
    friend void sync(Probe & p, const Anamnesis & a);
}
class Anamnesis{
    friend void sync(Anamnesis & a, const Probe & p);
    friend void sync(Probe & p, const Anamnesis & a);
}

inline void sync(Anamnesis & a, const Probe & p){
}

inline void sync(Probe & p, const Anamnesis & a){
}

Anamnesis a;
Probe p;
sync(a, p);