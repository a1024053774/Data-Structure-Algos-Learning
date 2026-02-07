//
// Created by 10240 on 2024/11/2.
//

//2023 T2
//字符串模式匹配，给定一个字符串，匹配出所有符合XOO的字符串，并输出
//如： a="abccbaascsdcccb"
//输出 bcc,baa,dcc


#include <iostream>

void Find_XOO(char *s){
    int len = strlen(s);//获取字符串长度
    if (len < 3) return;         // 长度检查

    for(int i = 0;i < len - 2;i++){
        if(s[i] != s[i+1] && s[i+1] == s[i+2]){
            cout<<s[i]<<s[i+1]<<s[i+2];
        }
    }
}

//时间复杂度O(n) n为字符串长度
//空间复杂度:O(1)
