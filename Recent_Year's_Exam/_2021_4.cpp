//
// Created by 10240 on 2024/10/28.
//

//2021年真题4

//给定一个字符串，请找出其中不含有重复字符的最长子串的长度

/*
思路分析：
使用滑动窗口，窗口内的字符不重复
使用一个数组记录字符上次出现的位置
遍历字符串，i作为右边界
如果字符已经在窗口中出现过
更新左边界到重复字符的下一个位置
记录当前字符的位置
更新最大长度
时间复杂度：O(n) n为字符串长度
空间复杂度：O(1) 256个字符
 */

#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    // window数组记录字符上次出现的位置
    int window[256] = {0};  // 初始化为0
    // 初始化为-1表示未出现过
    for(int i = 0; i < 256; i++) {
        window[i] = -1;
    }

    int maxLen = 0;    // 最大长度
    int left = 0;      // 窗口左边界
    //字符串长度
    int len = 0;
    while(s[len] != '\0') {
        len++;
    }


    // 遍历字符串，i作为右边界
    for(int i = 0; i < len; i++) {
        // 如果字符已经在窗口中出现过
        if(window[s[i]] >= left) {
            // 更新左边界到重复字符的下一个位置
            left = window[s[i]] + 1;
        }
        // 记录当前字符的位置
        window[s[i]] = i;
        // 更新最大长度
        if(i - left + 1 > maxLen){
            maxLen = i - left + 1;
        }
    }

    return maxLen;
}