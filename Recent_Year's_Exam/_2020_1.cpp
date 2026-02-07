//
// Created by 10240 on 2024/10/23.
//

//2020.1
    //1.将队列Q中的元素逆序
    //2.输出队列Q中重复的元素

    //思想
    /*
    借助栈实现，队列特性是先进先出，栈特性是先进后出，
    先将队列中元素输出到栈中，并统计重复个数，记录在数组R中，索引对应队列中元素的值，
    再将栈的元素输出到队列里


    */
    //时间复杂度 O(n^3)n为队列长度
    //空间复杂度 O(n^2)新建了一个栈和R数组

    #include <iostream>

    void Reverse(Queue &q){
        int stack[maxsize];
        int top = -1;
        int R[maxsize] = {0};  // 添加初始化

        while(front != rear){
            R[q[front]] += 1;
            stack[++top] = q[front++];
        }


        front = 0;
        rear = 0;
        while(top!= -1){
            q[rear++] = stack[top--];
        }

        for(int i = 0;i<n;i++){
            if(R[i] >= 2){
                cout<<i;
            }
        }

    }