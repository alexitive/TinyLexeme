#include <iostream>
#include <vector>
#include <fstream>//ifstream读文件，ofstream写文件，fstream读写文件
#include <string.h>
#include "action.h"


using namespace std;


// 根据action_list.txt 和 goto_list.txt构造语法分析表

// 把每一个空格的元素转换为Action类型并赋值
Action ParseElementToAction(string element)
{
    Action action;
    // 此空格没有值
    if(element == "null"){
        action.action_type = ERROR;
        action.shift_num = -1;
        action.reduce_type = DO_NONE;
        return action;
    }
    // 没有进行其他错误判断，比如"s222",假定输入没问题
    // 移入
    else if(element[0] == 's')
    {
        action.action_type = SHIFT;
        action.shift_num = int(element[1]);
        action.reduce_type = DO_NONE;
    }
    else if(element[0] == 'r')
    {
        action.action_type = REDUCE;
        action.shift_num = -1;
        action.reduce_type = DO_NONE;
    }
    else if(element == "acc")
    {
        action.action_type = ACCEPT;
        action.shift_num = -1;
        action.reduce_type = DO_NONE;
    }
    // 其他情况处理成与"null"相同

    action.action_type = ERROR;
    action.shift_num = -1;
    action.reduce_type = DO_NONE;
    return action;


}



vector<vector<Action> > GenerateActironTable(string file_path)
{
    // file_path = action_list.txt

    vector<vector<Action> > res;
    ifstream infile;
    // ifstream infile(file_path);
    infile.open(file_path, ios::in);
    string str_line;
    char char_str_line[512];
    if(infile) {
        while (getline(infile, str_line))
        {
            // 处理一行字符串
            vector<Action> line;
            // cout<<str_line<<endl;
            strcpy(char_str_line, str_line.c_str());
            cout<<char_str_line<<endl;
            char* token = strtok(char_str_line, ",");
            while (token != NULL)
            {
                // 可能出错
                line.push_back(ParseElementToAction(string(token)));
                // 继续切分
                token = strtok(NULL, ",");
            }
            res.push_back(line);
        }

    }
    infile.close();

    return res;
} 




vector<vector<int>> GenerateGotoTable(string file_path)
{
    vector<vector<int>> res;

    ifstream infile;
    // ifstream infile(file_path);
    infile.open(file_path, ios::in);
    string str_line;
    char char_str_line[512];
    if(infile) {
        while (getline(infile, str_line))
        {
            // 处理一行字符串
            vector<int> line;
            cout<<str_line<<endl;
            // strcpy(char_str_line, str_line.c_str());
            // cout<<char_str_line<<endl;
            // char* token = strtok(char_str_line, " ");
            // while (token != NULL)
            // {
            //     line.push_back(int(token));
            //     // 继续切分
            //     token = strtok(NULL, ",");
            // }
            line.push_back(str_line[0]);
            cout<<str_line[0]<<endl;
            res.push_back(line);
        }

    }
    infile.close();



    return res;
} 


// test
int main()
{
    // string path = "action_list.txt";
    // vector<vector<Action> > action = GenerateActironTable(path);
    string path2 = "goto_list.txt";
    vector<vector<Action> > gt = GenerateActironTable(path2);

    return 0;

}