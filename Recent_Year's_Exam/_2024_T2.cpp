//
// Created by 10240 on 2024/11/26.
//
//2024_T2
//设计一个数据结构，可以实现下述操作。WRITE X 表示输入一个字符X,UNDO X 表示删除一个字符X，REDO表示撤销上一步操作，READ表示输出字符。
//如输入arr = {"WRITE A","WRITE C","UNDO","READ","REDO","READ"}，输出 AB ABC

#include <iostream>
#include <string>
#define MAXSIZE 100

using namespace std;

typedef struct Stack {
    char data[MAXSIZE];
    int top;
} Stack;

// 自定义字符串长度计算函数
int strlength(string arr[]) {
    int len = 0;
    while (arr[len] != '\0') {//巧思：len为长度，同时也是下标
        len++;
    }
    return len;
}

void dataStruct(Stack &s1, Stack &s2, string arr[]) {
    int len = strlength(arr);
    for (int i = 0; i < len; ++i) {//获取每一个命令
        string command = arr[i];

        if (command.substr(0, 6) == "WRITE ") {//获取字串，从0开始，长度为6，为WRITE和一个空格的长度，判断是否为WRITE操作
        //substr(0, 6) 方法会从字符串下标位置 0 开始，获取长度为 6 的子串，也就是包含下标 0 到 5 的字符（共6个字符）。是一个左闭右开区间，不包含下标 6 的字符。
            // 提取字符X
            char value = command[6];
            s1.data[++s1.top] = value;
            // 写入操作后清空撤销栈
            s2.top = -1;
        } else if (command == "UNDO") {
            if (s1.top >= 0) {
                s2.data[++s2.top] = s1.data[s1.top--];
            }
        } else if (command == "REDO") {
            if (s2.top >= 0) {
                s1.data[++s1.top] = s2.data[s2.top--];
            }
        } else if (command == "READ") {
            for (int j = 0; j <= s1.top; ++j) {
                cout << s1.data[j];
            }
            cout << endl;//换行
        }
    }
}

int main() {
    string arr[] = {"WRITE A", "WRITE B", "WRITE C", "UNDO", "READ", "REDO", "READ"};
    Stack s1, s2;
    s1.top = -1;
    s2.top = -1;

    dataStruct(s1, s2, arr, len);

    return 0;
}


