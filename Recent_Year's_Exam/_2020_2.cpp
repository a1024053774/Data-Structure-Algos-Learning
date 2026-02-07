//
// Created by 10240 on 2024/10/23.
//
#include <iostream>
//2020.2
// 1.在顺序表中查找第一个元素值等于x的元素，并返回其次序，
// 2.统计线性表中x出现的次数

    /*
    思想：
    设置count变量，记录出现的次数，
    在第一次遇到x时，将下标赋给index，然后continue
    退出该循环体
    在进入下一个循环，计算count
    最后return index即可
    返回类型为int

    */

    typedef struct
    {
        int data[maxsize];
        int length;
    } Sqlist;

int Find(SqList L,int x){
    int count = 0;
    int index = -999;

    if(L.length <= 0) {
        return -888;//表示错误
    }

    // ********一次遍历同时完成查找和计数*******
    for(int i = 0; i < L.length; i++) {
        if(L.data[i] == x) {
            count++;
            // 记录第一次出现的位置
            if(index == -999) {
                index = i;
            }
        }
    }

    // 输出统计结果
    cout << "x出现的次数是" << count << endl;

    // 返回结果
    return index;  // 如果没找到会返回-1

}
//时间复杂度：O(n)
//空间复杂度:O(1)