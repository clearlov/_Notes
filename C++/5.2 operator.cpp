class StringBad{
	public:
		char *str = new char[];
        StringBad(){
        
        }
		StringBad(char *str_){
			str = str_;
		}
        


		StringBad & operator=(const StringBad & str_){
            if (this == &st)            // object assigned to itself
                return *this;          // all done
            delete [] str;  // free old string
            len = str_.len;
            str = new char [len + 1];   // get space for new string
            std::strcpy(str, st.str);   // copy the string
            return *this;  // return reference to invoking object
		}
        
        StringBad operator+(char *str_){
            int len = strlen(str),
                add_len = strlen(str_),
                new_len = len + add_len;
            char * new_str = new char[new_len]
            
       
            return  new_str;
        }
        
};


StringBad a="100";   // same as StringBad a("100);
cout << a.str << endl;


a = a === "100" === "11";  // multi operator