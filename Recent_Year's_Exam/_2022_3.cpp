//
// Created by 10240 on 2024/10/31.
//
//2022 T3
//给定一个字符串，将其中数字存入num数组中，如：
//"a123xy456",num[0]存放123，num[1]存放456

/*
解题思路：
遍历字符串的每一个字符
判断字符是否为数字
如果是数字，开始收集连续的数字
将收集到的数字转换并存入数组
需要记录当前数组的索引位置
*/
#include <iostream>

void extractNums(char *s,int *num){
    int len = strlen(s);//求数组长度
    int numIndex = 0;//num数组当前的索引
    int currentNum = 0;//当前位置的数字
    int isCollect = 0;//当前是否正在收集的状态

    for (int i = 0; i < len; i++) {
        // 判断是否为数字
        if (str[i] >= '0' && str[i] <= '9') {
            // 将字符转换为数字并累积
            currentNum = currentNum * 10 + (str[i] - '0');
            /*
            str[i] - '0'：
            '1' - '0' = 1
            '2' - '0' = 2
            '3' - '0' = 3
            对于数字 "123"：
            第1步：currentNum = 0 * 10 + (1) = 1
            第2步：currentNum = 1 * 10 + (2) = 12
            第3步：currentNum = 12 * 10 + (3) = 123
            */
            isCollecting = 1;
        } else {
            // 如果之前正在收集数字，现在遇到非数字字符
            if (isCollecting) {//说明前面转换了数字
                // 将收集的数字存入num数组
                num[numIndex++] = currentNum;

                // 重置收集状态
                currentNum = 0;
                isCollecting = 0;
            }
        }
    }

    // 最后位置若是数字，会将状态置为1，但是循环已结束，不会将数保存
    //需要手动操作一下
    if (isCollecting) {
        num[numIndex] = currentNum;
    }
}

//时间复杂度：O(n)，其中 n 是字符串长度
//空间复杂度：O(1)，除了输入和输出数组外，只使用了几个额外变量
