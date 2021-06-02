#include <iostream>
#include "action.h"
using namespace std;


int main()
{
    Action action(REDUCE,1,DO_ID);
    
    if(action.action_type != ERROR) action.toString();

    return 0;

}




