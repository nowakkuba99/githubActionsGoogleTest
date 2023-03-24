#ifndef D4AB7306_0F6F_4356_8C90_68FC5EB5D2AC
#define D4AB7306_0F6F_4356_8C90_68FC5EB5D2AC

/*
    Define test class that will be unit tested
           Created by Jakub Nowak 2023.
*/
#include <string>

class TestClass
{
public:
    static int functionToTest(int a, int b)     // Static function with simple add operation
    {
        return a + b;
    }

    static std::string getLogo()
    {
        const std::string m_logo = R"(
 _____             _     _____         _   
|   __|___ ___ ___| |___|_   _|___ ___| |_ 
|  |  | . | . | . | | -_| | | | -_|_ -|  _|
|_____|___|___|_  |_|___| |_| |___|___|_|  
              |___|                        
                                           
 _                 _     _                 
| |_ ___ _____ ___| |___| |_ ___           
|  _| -_|     | . | | .'|  _| -_|          
|_| |___|_|_|_|  _|_|__,|_| |___|          
              |_|                  
    )";
        return m_logo;
    }
};

#endif /* D4AB7306_0F6F_4356_8C90_68FC5EB5D2AC */
