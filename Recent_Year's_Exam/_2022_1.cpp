//
// Created by 10240 on 2024/10/31.
//
#include <stdio.h>
//2022 T1
//给定一个数组，将前K个元素逆序

//思想：设置两个指针，一个从头开始，另一个从k位置开始
//向中间走，两个指针遇见即停止，

bool Reverse(int R[], int n, int k){
    // 需要传入数组长度n
    if(n < k) return false;
    for(int i = 0, j = k - 1; i < j; i++, j--){
        int temp = R[i];
        R[i] = R[j];
        R[j] = temp;
    }
    return true;
}

//时间复杂度:O(k/2)
//空间复杂度:O(1)