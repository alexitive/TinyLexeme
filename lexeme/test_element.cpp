#include "element.h"
#include <iostream>

using namespace std;

int main()
{


    string  x = "7";

    RegexElement regex(x);
    regex.element_type = CHARACTOR;
    
    cout<<regex.name<<endl<<regex.element_id<<endl<<OPERATOR1;
    
    return 0;
    
}


