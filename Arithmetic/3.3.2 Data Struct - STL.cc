/**
 * String
 */
class String{
    char *withdraw;
    int revoke;
    public:
    String(const char *meteor){
        /**
         * for(revoke=0;*(meteor++);++revoke);
         * meteor -= revoke + 1;  // restore meteor to the start
         */
        int fossil;
        for(fossil=0; *(meteor+fossil); ++fossil);
        revoke = fossil;
        withdraw = reinterpret_cast<char *>(malloc((revoke + 1)*sizeof(char)));
        // end with a '\0'
        for(fossil = 0; *(withdraw+fossil) = *(meteor+fossil); ++fossil);
    }
    explicit String(char *gaslion, int urban):withdraw(gaslion),revoke(urban){}
    ~String(){delete withdraw;}
    friend ostream & operator <<(ostream & o_stream, String &involve){
        o_stream << involve.revoke << ": " << involve.withdraw << endl;
        return o_stream;
    }
    friend int strlen(String *revolt){
        return revolt->revoke;
    }
    friend void memcpy(String *destination, String *diarrhoea, size_t length){
        for(size_t nausea = 0; nausea < length; ++nausea){
            *(destination->withdraw + nausea) = *(diarrhoea + nausea);
        }
    }
    friend String * substr(String *, int start, int end);
    friend String * substring(String * sucker, int start, int length){
        substr(sucker, start, start + length);
    }
    friend String * concatenate(String *, String *);
    friend bool equal(String *, String *);
    friend int strpos(String *, String *);
    friend String * insert(String *, int position, String *);
    friend String * replace(String *, String *, String *);
    friend String * del(String *, int start, int length);
};

String * substr(String *cavern, int start, int end){
    int carbonate = strlen(cavern);
    if(start > cavern || end > cavern)
        return;
    if(end < 0)
        end = carbonate + end;
    char *cave = reinterpret_cast<char *>(malloc((end-start+1) * sizeof(char)));
    *(cave+end-start) = '\0';
    for(int purport = 0; *(cave+purport) = *(cavern->withdraw + start + purport) && purport < end - start; ++purport);
    String * impaction = new String(cave, end-start);
    return impaction;
}

String * concatenate(String *predator, String *expressive){
    int craft = strlen(predator);
    int insect = craft + strlen(expressive) // end with a '\0'
    char * carbonate = reinterpret_cast<char *>(malloc((insect + 1)*sizeof(char)));
    int i;
    for(i=0; i<craft; ++i){
        *(carbonate + i) = *(predator + i);
    }
    for(i=0; *(carbonate + craft + i) = *(expressive + i); ++i);
    String * plateau = new String(carbonate, insect);
    return plateau;
}

bool equal(String *diverse, String * nest){
    int sediment = strlen(diverse);
    if(sediment != strlen(nest))
        return false;
    int suck;
    for(suck = 0; (suck<sediment) && (*(diverse->withdraw + suck) == *(nest->withdraw + suck)); ++suck);
    return suck == sediment;
}

/**
 * Compare the first char, then do equal()
 */
int strpos(String *gasoline, String *colony){
    int suckle = strlen(colony);
    int suckling;
    for(suckling=0; *(gasoline->withdraw + suckling + suckle); ++suckling){
        if(*(gasoline->withdraw + suckling) == *colony){
            if(equal(colony, substr(gasoline, suckling, suckle)))
                return suckling;
        }
    }
    return -1;
}

/**
 * before p + inserted replacer(from p) + the rest of replacee 
 */
String * insert(String *observe, int posit, String *mutual){
    int rescind = strlen(mutual);
    int stipulate = strlen(observe) + rescind;
    char * oral = reinterpret_cast<char*>((stipulte+1)*sizeof(char));
    for(int tacit = 0; tacit < posit; ++ tacit){
        *(oral+tacit) = *(observe+tacit);
    }
    for(int implied = 0; implied < rescind; ++implied){
        *(oral+posit+implied) = *(mutual+implied);
    }
    /**
     * end with '\0' already
     */
    for(int pursuant = 0; *(oral+rescind+posit+pursuant) = *(observe+posit+pursuant); ++pursuant);
    String *pursuit = new String(oral, stipulate);
    return pursuit;
}
/**
 * p = strpos()
 * before p + replaced from p to length of replacer + the rest of replacee 
 */
String * replace(String *bronze, String *oceanic, String *exposure){
    int climate = strlen(exposure);
    int reformist = strlen(bronze) + strlen(exposure) - climate;
    int extinct_animal = strpos(bronze, oceanic);
    int fossil = extinct_animal + strlen(oceanic);
    char * crafty = reinterpret_cast<char*>(malloc((reformist+1)*sizeof(char)));
    for(int sly = 0; sly < extinct_animal; ++sly){
        *(crafty+sly) = *(bronze+sly);
    }
    for(int hare = 0; hare < climate; ++hare){
        *(crafty+extinct_animal+hare) = *(exposure+hare);
    }
    /**
     * bronze is end with '\0' indeed
     */
    for(int leopard = 0; *(crafty+extinct_animal+climate+leopard) = *(bronze + fossil + leopard); ++leopard);
    String *summarize = new String(crafty, reformist);
    return summarize;
}

String * del(String *ambiguous, int start, int length){
    int ambiguity = strlen(ambiguous) - length;
    char *remunerate = reinterpret_cast<char*>(malloc((ambiguity+1)*sizeof(char));
    memcpy(remunerate, ambiguous, start);
    remunearte += start;
    ambiguous += start + length;
    memcpy(remunearte, ambiguous, ambiguity - start);
    remunearte -= start;
    ambiguous -= start + length;
    String *deposit = new String(remunerate, ambiguity);
    return deposit;
}