#include <iostream>
#include <fstream>//ifstream读文件，ofstream写文件，fstream读写文件
#include <string>

#include "element.h"
#include "regular_expression.h"

using namespace std;

LexcialType selectclass(string head) ;
bool Isoperator(string str) ;
bool Iskeyword(string str , vector<string> heads);



LexcialType selectclass(string head) {
    if (head == "int") {
        return NUMERIC;
    }
    else if (head == "keyword") {
        return RESERVED;
    }
    else if (head == "operator") {
        return OPERATOR2;
    }
    else if (head == "id") {
        return IDENTIFIER;
    }
    exit(0);
}



bool Isoperator(string str) {
    if (str == "&" || str == "|" || str == "#" || str == "?" || str == "@" || str == "(" || str == ")")
        return true;
    return false;
} 

bool Iskeyword(string str , vector<string> heads) {
    int size = heads.size();
    //for (auto head : heads) {
    for (int i = 0 ; i < size ; i++){
        if (heads[i] == str)
        {
            return true;
        }
    }
    return false;
}

vector<RegexExpression> lexicalAnalysis()
{

    ifstream infile;
    infile.open("regex_sample.txt", ios::in);
    string str_line;
    char cstrline[512];
    vector<string> heads;
    if (infile) {
        while (getline(infile, str_line)) {
            strcpy(cstrline, str_line.c_str());
            char* Token = std::strtok(cstrline, " ");
            string head = "", body = "";
            if (Token != NULL) {//先取头部！
                head = Token;
            }
            heads.push_back(head);
            // cout << head << endl;
        }   
    }
    infile.close();
    infile.open("regex_sample.txt", ios::in);
    vector<RegexExpression> regex_list;
    if (infile) {
        while (getline(infile, str_line))
        {
            // int num = 1;
            vector<RegexElement> velement;
            // cout << str_line << endl;
            strcpy(cstrline , str_line.c_str());
            // cout << cstrline << endl;
            char* Token = std::strtok(cstrline, " ");
            string head = "", body = "";
            if (Token != NULL) {//先取头部！
                head = Token;
            }
            else {
                cout << "表达式不合法! 无头部！" << endl;
                exit(0);
            }
            Token = std::strtok(NULL, " ");
            if (Token == NULL) {
                cout << "表达式不合法! 无转换符！" << endl;
                exit(0);
            }
            // cout << head << endl;
            Token = std::strtok(NULL, " ");
            while (Token != NULL) {
                string temp = Token;
                // cout << temp << endl;
                RegexElement* rp = new RegexElement(Token);
                // rp->element_id = num++;
                // rp->name = Token;
                if (Iskeyword(temp , heads)) {//先判断是否是关键字
                    rp->element_type = VARIANT;
                }
                else if (Isoperator(temp) && temp.size() == 1) {
                    rp->element_type = OPERATOR1;
                }
                else {
                    rp->element_type = CHARACTOR;
                }
                velement.push_back(*rp);
                Token = std::strtok(NULL, " ");
            }
            RegexExpression* rpexpression = new RegexExpression(head);
            rpexpression->lexcial_class = selectclass(head);
            rpexpression->head.name = head;
            rpexpression->head.element_id = 0;
            //rpexpression->head.element_id = -1;
            rpexpression->head.element_type = VARIANT;
            rpexpression->body = velement;
            regex_list.push_back(*rpexpression);
        }
    }
    else// 该文件不存在
    {
        cout << "can not open this file" << endl;
    }
    infile.close();
    // 单行处理
    // RegexExpression regex = regex_list[1];
    // cout << regex.lexcial_class << endl;
    // cout << regex.head.name << endl;
    // cout << regex.body.size() << endl;
    // int size = regex.body.size();
    // for (int i = 0 ; i < size ; i++) {
    //     RegexElement temp = regex.body[i];
    //     cout << temp.element_id << " " << temp.element_type << " " << temp.name << " " << endl;
    // }
    return regex_list;
}


// 测试函数

int main()
{
    vector<RegexExpression> regexExeList = lexicalAnalysis();
    
    for (int i = 0; i < regexExeList.size(); i++) {
        regexExeList[i].PrintExpression();
    }


    return 0;
}











