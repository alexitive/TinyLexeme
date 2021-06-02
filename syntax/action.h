#ifndef ACTION_H
#define ACTION_H
#include <iostream>

using namespace std;

typedef enum
{
    // 错误
    ERROR = 0,
    // 移入
    SHIFT = 1,
    // 规约
    REDUCE = 2,
    // 接受
    ACCEPT = 3
}ActionType;

typedef enum
{
    // 按照哪一个产生式进行规约
    // 规约错误
    DO_NONE = 0,
    // E ~ E | E
    DO_OR = 1,
    // E ~ E & E
    DO_AND = 2,
    // E ~ (E)
    DO_BRACKET = 3,
    // E ~ E#
    DO_PLUS_CLOSURE = 4,
    // E ~ E@
    DO_CLOSURE = 5,
    // E ~ E#?
    DO_ZERO_ONE = 6,
    // E ~ id
    DO_ID = 7

}ReduceType;


class Action
{

public:
    Action() {}
    Action(ActionType action_type, int shift_num, ReduceType reduce_type);
    ~Action();

    void toString();

    ActionType action_type;
    // 表示移入的新状态,状态从1开始,0表示错误的状态
    int shift_num;
    // 规约的产生式
    ReduceType reduce_type;

};


Action::Action(ActionType action_type, int shift_num, ReduceType reduce_type)
{   
    this->action_type = action_type;
    this->shift_num = shift_num;
    this->reduce_type = reduce_type;
}

// 打印Action函数
void Action::toString()
{
    cout<<"action_type: "<<action_type<<" "
    <<"shift_num: "<<shift_num<<" "
    <<"reduce_type_num: "<<reduce_type<<endl;
}

Action::~Action()
{
}


#endif