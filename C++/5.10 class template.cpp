template <class Type>
class Fossil
{
private:
	enum{ SIZE = 10 };
	int dinosaurs;
	Type * petrifactions;
	int top = 0;
public:
	explicit Fossil(int n = SIZE) :dinosaurs(n){
		petrifactions = new Type[n];
	}
	bool push(const Type &item){
		if (top < dinosaurs){
			petrifactions[top] = item;
			top++;
			return true;
		}
		else{
			return false;
		}
		
	}
	Type * get(){
		return petrifactions;
	}
	~Fossil(){ delete[] petrifactions; }

};

int size = 2;
	Fossil<int> fs(size);
	fs.push(1);
	fs.push(5);
	int * arr1 = fs.get();
	for (int i = 0; i < size; i++){
		cout << arr1[i] << endl;
	}
	
	Fossil<char *> fs2(size);
	fs2.push("petrol");
	fs2.push("gasoline");
    
    
/*****************************************************************/
template <class T, int N>
class Adamant{
private:
    T arr[N];  // T and N are all from template
public:
Adamant(){};
explicit Adamant(const T &v);
virtual T & operator[](int i);
virtual T operator[](int i) const;
}

template <class T, int N>
Adamant<T,N>::Adamant(const T &v){
    for(int i = 0; i < N; i++){
        arr[i] = v;
    }
}

template <class T, int N>
T & Adamant<T,N>::operator[](int i){
    if(i<0 || i >=n){
        std::cerr << i << " is out of range";
        std::exit(EXIT_FAILURE);
    }
    return arr[i];
}

template <class T, int N>
T Adamant<T,N>::operator[](int i) const{.
    if(i<0 || i >=n){
        std::cerr << i << " is out of range";
        std::exit(EXIT_FAILURE);
    }
    return arr[i];
}


/*****************************************************************/

template <typename T>
class Arr{
private:
    T entry;
}

template <typename T>
class Stack{
private:
    Arr<T> arr;
}

Arr< Stack<int> > arr;



