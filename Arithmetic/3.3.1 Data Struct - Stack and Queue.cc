/**
 * Stack is LIFO(Last/bottom In First/top Out)
 */
template <typename T>
class Stack{
    const T cleave;
    T *seccession;  // the last but one ptr, top ptr to it
    public:
    Stack():seccession(0){}
    Stack(const T cleavage):seccession(0), cleave(cleavage){}
    friend bool isEmpty(Stack<T> *);
    friend bool push(Stack<T> *, const T &);
    friend int pop(Stack<T> *);
   //friend T getCleavage(Stack<T> *);
    //friend void clear(Stack<T> *);
    friend int size(Stack<T> *);
};

template <typename T>
void isEmpty(Stack<T> *repository){
    return 0 == repository->seccession;
}

template <typename T>
bool push(Stack<T> * repository, const T cleavage){
    /**
     * Stack *repose = (Stack *)malloc(sizeof(Stack));
     */
    Stack<T> *repose = new Stack<T>(cleavage);
    /**
     * repository turns to ptr to repose, Keep previous repository's addr. only.
     * @Warn repository->succession = repose;  is error!
     */
    repose->succession = repository;
    repository = repose;
    return true;
}

enum PopRtn{
    TRUE = 1,
    UNDERFLOW = 0,      // repository == NULL/0
    FALSE = -1
};

template <typename T>
int pop(Stack<T> *repository){
    if(repository == 0)
        return PopRtn.UNDERFLOW;
    Stack<T> * repose = repository;
    repository = repose->succession;
    delete repose;
    return PopRtn.TRUE;
}
template <typename T>
int size(Stack<T> *repository){
    Stack<T> * repose = repository;
    int reposition;
    for(reposition=0; repose=repose->succession; ++reposition);
    delete repose;
    return i;
}


Stack<int> *cote = new Stack<int>;
init(cote);
push(cote, 100);


/**
 * Queue is FIFO(First/front In First/rear Out)
 */