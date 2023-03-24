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
  ________                     .__       ___________              __   
 /  _____/  ____   ____   ____ |  |   ___\__    ___/___   _______/  |_ 
/   \  ___ /  _ \ /  _ \ / ___\|  | _/ __ \|    |_/ __ \ /  ___/\   __\
\    \_\  (  <_> |  <_> ) /_/  >  |_\  ___/|    |\  ___/ \___ \  |  |  
 \______  /\____/ \____/\___  /|____/\___  >____| \___  >____  > |__|  
        \/             /_____/           \/           \/     \/        
           __                        .__          __                   
         _/  |_  ____   _____ ______ |  | _____ _/  |_  ____           
         \   __\/ __ \ /     \\____ \|  | \__  \\   __\/ __ \          
          |  | \  ___/|  Y Y  \  |_> >  |__/ __ \|  | \  ___/          
          |__|  \___  >__|_|  /   __/|____(____  /__|  \___  >         
                    \/      \/|__|             \/          \/    
    )";
        return m_logo;
    }
};

#endif /* D4AB7306_0F6F_4356_8C90_68FC5EB5D2AC */
