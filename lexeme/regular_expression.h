#ifndef REGULAR_EXPRESSION_H
#define REGULAR_EXPRESSION_H

#include <vector>
#include "element.h"
#include <string>

using namespace std;

typedef enum
{
    // 正则表达式的词法类型，暂时三种以满足TINY语言的需要，对以后的类型可以进一步扩展
   
    //表示TINY语言的变量 
    IDENTIFIER = 0,
    //表示TINY语言的整数常量
    NUMERIC = 1,
    // 表示TINY语言的保留字
    RESERVED = 2,
    // 表示TINY的操作符
    OPERATOR2 = 3
}LexcialType;

class RegexExpression
{

public:
    RegexExpression() {}
    RegexExpression(RegexElement head);
    void PrintExpression();
    // 正则表达式头部
    RegexElement head;
    // 正则表达式主体
    vector<RegexElement> body;
    // 正则表达式类型
    LexcialType lexcial_class;
    // 注释
    string remark;


};

RegexExpression::RegexExpression(RegexElement head)
{
    this->head = head;
};

void RegexExpression::PrintExpression()
{
    cout<<"head"<<endl;
    head.PrintElement();

    // for(int i = 0; i < body.size(); i++){

    // }
    cout<<"body"<<endl;
    vector<RegexElement>::iterator iter;
    for(iter=body.begin(); iter != body.end(); iter++){
        (*iter).PrintElement();
    }

}

#endif



