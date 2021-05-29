#include "element.h"
#include "regular_expression.h"
#include <iostream>

using namespace std;

int main()
{


    string head = "OPERATOR";
    RegexElement regex1(head);
    regex1.element_type = OPERATOR1;

    string body1 = ":";
    RegexElement regex2(body1);
    regex2.element_type = CHARACTOR;



    string body2 = "=";
    RegexElement regex3(body2);
    regex3.element_type = CHARACTOR;

    RegexExpression regexExp(regex1);
    regexExp.lexcial_class = OPERATOR2;

    regexExp.body.push_back(regex2);
    regexExp.body.push_back(regex3);

    regexExp.PrintExpression();

    return 0;
    
}


