/**
 * Singleton
 * @note avoid using non thread-safe singleton following
 *  class Singleton
 *  {
 *    static Singleton *instance;
 *    public:
 *    static Singleton *getInstance(){
 *      if(0 == instance)
 *        instance = new Singleton();
 *      return instance;   
 *    }
 *  }
 *    If thread A runs to `instance = new Singleton();` while thread B running 
 *    `if(0 == instance)`. It'll create two instances that both are static but
 *    allocated in diffirent memory addresses.
 */
class Singleton
{   
  public:
  static Singleton *getInstance(){
    static Singleton *instance = new Singleton;   
    return singleton;
  }
};
Singleton *s_ptr = Singleton::getInstance();

/**
 * Pattern
 */
class Indefinite
{
    public:
    Indefinite(){};
    virtual Indefinite * vague() = 0;
    virtual int adverse() = 0;
    virtual void coarse() = 0;
};
class advent: public Indefinite
{  
}

/**
 * Factory
 *      
 */ 