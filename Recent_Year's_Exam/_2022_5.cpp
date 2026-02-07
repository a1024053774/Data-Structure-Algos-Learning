//
// Created by 10240 on 2024/11/1.
//
//2022 T5

//实现一个栈，能够实时记录栈中元素的最大值，即在栈的基础上实现函数Max
//能够返回栈中所有元素的最大值

//思想
//在第一次入栈时，将它的值赋值给Max
//当栈的++top指针的时候，与之前的Max值比较，若大于，更新Max的值
//当top--，也就是出栈的时候，当出栈的值等于Max的值，说明这个值是最大值，需要更新Max的值
//时间复杂度：O(1)
//空间复杂度：O(n) 开辟了一个新的辅助栈

#include <iostream>
#define MAX_SIZE 100

int top = -1;
int max_top = -1;
int main_stack[MAX_SIZE];
int max_stack[MAX_SIZE];

int push(int x){
    if(top == MAX_SIZE -1){//栈已满
        return -999;
    } else {
        main_stack[++top] = x;
        if(max_top == -1 || x > max_stack[max_top]){
            max_stack[++max_top] = x;
        }
        return 999;//入站成功
    }
}

int pop(){
    if(top == -1){
        return -999;//栈空
    } else {
        int num = main_stack[top--];
        if (num == max_stack[max_top]){
            max_top--;
            return num;//若弹出的刚好是最大值，返回这个最大值
        }
        return num;//返回弹出的普通值
    }
}

int get_Max(){
    if(max_top != -1){
        return max_stack[max_top];
    } else {
        return -999;
    }
}