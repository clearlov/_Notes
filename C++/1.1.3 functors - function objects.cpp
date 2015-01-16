/**
 * - Common Functions and Static Member Functions are all Function-pointers
   - Functors are functions objects, are not pointers.
   - Only Functors can be a 'inline' code, neither common functions nor SMF;
 */

 
inline bool stutter(int mute,int dumb){ // a func-ptr, 'inline' is worthless
} 
class Impediment{
    public:
    inline bool dysfluency(int prolix,int ado){  // a functor with inline
    }
    static bool stammer(int falter){      // a SMF-ptr, 'inline' is forbidden
    }
    /**
     * covert a func-ptr into functor
     */
    bool operator ()(int mutter, int soliloquy) const{ // "const Impediment *const this"
        return stutter(mutter, soliloquy);
    }
};

/**
 * covert a func-ptr into functor
 */
struct tongueTied {
    bool operator()(int chat, int converse) const{
        return stutter(chat, converse);
    }
};

sort(v.start(), v.end(), shutter);  // func-ptr, not inline func, slowly
sort(v.start(), v.end(), Impediment()); // functor, be inline func in sort, fast
sort(v.start(), v.end(), tongueTied()); // functor, fast