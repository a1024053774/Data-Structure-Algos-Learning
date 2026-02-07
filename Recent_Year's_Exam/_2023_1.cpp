//
// Created by 10240 on 2024/11/2.
//
//2023 T1
////给定一个数组，输出数组中最小元素对，最小元素对即相邻的两个元素和最小。例如：
//a=[1,4,5,10,2,-2]
//输出:(2,-2);

//思想：
//用两个指针low和fast，一个初值赋给0，一个初值赋给1，开始向后遍历，若求和小于low，更新low，并用pos1和pos2保存这两个最小对的索引
//若有相同的元素对之和，以上一个为准

#include <iostream>
void Find_smallestPair(int a[],int n){
    if(n < 2) return;//数组长度小于2则返回
    int low = INT_MAX;
    int slow = 0;
    int fast = 1;
    int pos1 = 0;
    int pos2 = 1;

    for(;fast < n;slow++,fast++){
        int currentSum = a[slow] + a[fast];
        if(currentSum < low){
            low = currentSum;
            pos1 = slow;
            pos2 = fast;
        }
    }

    cout<<"最小的元素对之和为"<< low <<"索引为"<< pos1 << ',' << pos2;
}

//时间复杂度O(n) n为数组长度
//空间复杂度:O(1)