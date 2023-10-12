#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

class PasswordGenerator {
    private:
        char data[50];
        
        int size=9;
        int lowLetters=0;
        int upLetters=0;
        int digits=0;
        int spcChar=0;
    
        char *res = new char[size];
        const char arr[70]={'a','b','c','d','e','f','g','h','i','j',  'k','m','n','o','p','q','r','s','t','u',  'v','w','x','y','z','A','B','C','D','E'  ,'F','G','H','J','K','L','M','N','P','Q',  'R','S','T','U','V','W','X','Y','Z','0',  '1','2','3','4','5','6','7','8','9','$',  '#','@','!','*','(',')','&','^','_','.'};

    public:
        void read(){
            std::fstream f("config.txt");
            if(!f.fail()){
                while(f>>data)
                {
                    std::cout << data << "  "; for(int k=0; k<sizeof(data)/sizeof(char); k++){if(data[k]==':'){std::cout << k << " ";}if(data[k]=='\0'){std::cout << k << " "; break;}}
                    std::cout << sizeof(data)/sizeof(char) << "\n";
                }
            }
            
        }
        
        PasswordGenerator(){ srand(time(0)); }
        ~PasswordGenerator(){ delete [] res; }
        
        void generator()
        {
            for(int x=0; x<sizeof(res)/sizeof(char); x++)
            {
                int limit = (sizeof(arr)/sizeof(char))-1;
                // generating a random element's position
                int r = rand()%(limit);
                
                // analyzing the password
                if(r<25){lowLetters++;}
                if(r>24 && r<49){upLetters++;}
                if(r>48 && r<59){digits++;}
                if(r>58 && r<=69){spcChar++;}
                
                res[x]=arr[r];
            }
        }
        
        char* getRes(){ return res; }
        
        void config()
        {
            std::cout << "Your config:\n ";
            std::cout << "size: " << size-1 << "\n lowLetters: " << lowLetters << "\n upLetters: " << upLetters << "\n digits: " << digits << "\n spcChar: " << spcChar;
            std::cout << "\n\n Would you like to change smth?";
        }
    };

int main()
{
    PasswordGenerator p;
    p.read();
    // std::cout << "\nres: " << p.getRes()<< "\n";
    // p.config();
   
    // options or config
    // easier(options): 1. more letters 2. more uppercase letters 3. more special characters
    // harder(config): 1. number of letters, number of uppercase letters, number of special characters 2. percents of it 
    return 0;
}
