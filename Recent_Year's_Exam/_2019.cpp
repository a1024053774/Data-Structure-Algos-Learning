//
// Created by 10240 on 2024/10/22.
//

/*2019真题

2、从扑克牌中随机抽5张牌、 判断是不是一个顺子
即这 5 张牌是不是连续的 2-10 为数字本身、 A为1,J为11,Q为12, K为13, 而大小王可以看成任意数字。
试编写程序实现这一判断。


思想：*/
//假设抽取的五张牌存储在char类型的数组中
//将char类型的扑克牌数组里的值赋值到int数组里，方便比较
bool func(char A[]) {
    int B[5];
    int j = 0;
    int kingCount = 0;

    // 转换字符为数字
    for(int i = 0; i < 5; i++) {
        if(A[i] >= '2' && A[i] <= '9') {
            B[j++] = A[i] - '0';
        } else if(A[i] == '1') {
            B[j++] = 10;
        } else if(A[i] == 'A') {
            B[j++] = 1;
        } else if(A[i] == 'J') {
            B[j++] = 11;
        } else if(A[i] == 'Q') {
            B[j++] = 12;
        } else if(A[i] == 'K') {
            B[j++] = 13;
        } else if(A[i] == '0' || A[i] == '*') {
            kingCount++;
            continue;
        }
    }

    // 插入排序（正确实现）
    int n = 5 - kingCount;
    for(int i = 1; i < n; i++) {
        int temp = B[i];
        j = i - 1;
        while(j >= 0 && B[j] > temp) {
            B[j + 1] = B[j];
            j--;
        }
        B[j + 1] = temp;
    }

    // 检查重复
    for(int i = 0; i < n-1; i++) {
        if(B[i] == B[i+1]) {
            return false;
        }
    }

    // 计算需要填补的空缺
    //已经排序之后
    int gaps = 0;
    for(int i = 0; i < n-1; i++) {
        gaps += B[i+1] - B[i] - 1;  // 计算相邻两个数之间需要填补的数量
        //当有2和9这两张牌时:
        // B[i+1] - B[i] - 1 = 9 - 2 - 1 = 6
        // 这表示在2和9之间需要填补6个数字(3,4,5,6,7,8)才能构成顺子。
    }

    return gaps <= kingCount;
}

//时间复杂度：O(1);
//空间复杂度：O(1);