#include <iostream>
#include <fstream>//ifstream读文件，ofstream写文件，fstream读写文件
#include <string>

#include "element.h"
#include "regular_expression.h"

using namespace std;


vector<RegexExpression> lexicalAnalysis()
{

    vector<RegexExpression> regex_list;

    // txt文件按行读取，然后进行切割，分为head和body
    // 每一个字符对应一个RegexElement,组装为一个RegexExpression

    // 从已有文件读入
    ifstream regex_file("regex_sample.txt");

    // 打开文件
    // if(!regex_file.is_open())
    // {
    //     cout << "can not open this file" << endl;
    // }

    string str_line = "";

    // 如果存在该文件
    if(regex_file){
        while(getline(regex_file, str_line))
        {
            cout << str_line << endl;


        }
    }
    else// 该文件不存在
    {
        cout << "can not open this file" << endl;        
    }
    

    regex_file.close();

    return regex_list;
    

}




// 测试函数

int main()
{
    lexicalAnalysis();

    return 0;
}








