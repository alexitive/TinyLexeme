#ifndef ELEMENT_H
#define ELEMENT_H

#include <bits/stdc++.h>

// string 存在于std命名空间里
using namespace std;


typedef enum
{
    // CHARACTOR表示一个输入字符 
    CHARACTOR = 0, 
    //VARIANT表示一个正则表达式名称
    VARIANT = 1, 
    //OPERATOR 表示一个运算符的名称
    OPERATOR1 = 2   
}
ElementType;

// typedef enum
// {
//     START, DONE, 
    
// }
// StateType;

class RegexElement
{
    
public:
    RegexElement() {}
    RegexElement(string name);
    void PrintElement();

    // element自增id，main()函数开始执行是初始化为0
    int element_id;
    // 自增计数器
    static int IDCOUNTER;
    // 元素所属类别
    ElementType element_type;
    // 元素名称
    string name;
    // 注释
    string remark;

};



int RegexElement::IDCOUNTER = 0;

RegexElement::RegexElement(string name)
    {
        this->name = name;
        this->element_id = this->IDCOUNTER;
        this->IDCOUNTER++;
    };


void RegexElement::PrintElement()
{
    cout<<"element_id: "<<this->element_id<<" "
    <<"regex.class_type: "<<this->element_type<<" "
    <<"regex.name: "<<this->name<<" "
    <<"regex.remark: "<<this->remark<<endl;
}

#endif
