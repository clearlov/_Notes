/**
 * Singleton
 */
class Singleton
{   
    static Singleton *singleton = 0;
    public:
    Singleton(){
        
    }
    static Singleton *getInstance(){
        if(*singleton == 0)
            singleton = new Singleton;
        return singleton;
    }
}

Singleton *s_ptr = Singleton::getInstance();