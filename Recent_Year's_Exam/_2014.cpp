//
// Created by 10240 on 2024/10/14.
//

//2014年真题
#include <stdio.h>
int reset(int a[],int l,int h,int x){
    int i,j,t;
    i = 1,j = h;
    while(i<j){
        while(i<j && a[j]>x) j--;
        while(i<j && a[i]<x) i++;
        if(i<j){
            t=a[j];
            a[j]=a[i];
            a[i]=t;
        }
    }
    if(a[i]<x){
        return i;
    } else {
        return i-1;
    }
}
/*(1)写出该函数的功能
(2)
写一个调用上述函数实现下列功能的算法。
对一个整形数组Y[n]中的元素进行重新排列，
将所有负数均调整到数组的低下标，
将所有正数均调整到数组的高下标端。
若有零值，则置于两者之间，并返回数组中零元素的个数。*/

//1.功能：将数组中的元素按照中枢值x进行重排，小于x的元素放在x的左边，大于x的元素放在x的右边
/*该函数 `reset` 的功能是对数组 `a` 进行分区，将小于等于 `x` 的元素放在数组的左侧，将大于 `x` 的元素放在数组的右侧，并返回分区的位置。
具体步骤如下：
1. 使用双指针法，`i` 从数组左侧开始，`j` 从数组右侧开始。
2. 从右向左扫描，找到第一个不大于 `x` 的元素。
3. 从左向右扫描，找到第一个不小于 `x` 的元素。
4. 交换这两个元素。
5. 重复步骤2到4，直到 `i` 和 `j` 相遇。
6. 如果分区点的元素小于 `x`，返回 `i`，否则返回 `i-1`。

这个函数的目的是将数组按照给定的值 `x` 进行分区，并返回分区的位置。*/


//2.算法
int Func(int Y[],int l,int h){
    int count = 0;
    if(l<h){
        int pivot_position = reset(Y,l,h,0);//以0为中枢
        count += Func(Y, l, pivot_position - 1);
        count += Func(Y, pivot_position + 1, h);
    }

    for(int m = 0;m < h;m++){
        if(Y[m] == 0){
            count++;
        }
    }

    return count;
}

int main() {
    int Y[] = { -1, 3, 0, -2, 5, 0, -3, 2 };
    int n = sizeof(Y) / sizeof(Y[0]);

    int zero_count = Func(Y, 0, n - 1);

    // 输出排序后的数组
    for(int i = 0; i < n; i++){
        printf("%d ", Y[i]);
    }

    // 输出零元素的个数
    printf("\nNumber of zeros: %d\n", zero_count);

    return 0;
}
