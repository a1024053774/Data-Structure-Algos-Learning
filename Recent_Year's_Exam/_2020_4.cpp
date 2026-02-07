//
// Created by 10240 on 2024/10/26.
//
//2020年真题4
/*代码说明
rotate180 函数遍历矩阵的前半部分，对称交换每对位置。
printMatrix 函数用于打印矩阵。
在 main 函数中，定义一个示例矩阵，调用 rotate180 函数对其进行旋转并输出结果。

复杂度分析
时间复杂度：O(n^2)，因为我们遍历矩阵的每个元素一次。
空间复杂度：O(1)，因为旋转是在原矩阵上就地完成的。*/

/*
*将一个
n×n 的矩阵旋转 180°，意味着将矩阵中的元素旋转半圈，相当于上下、左右方向均翻转。
* 如果我们把矩阵看成一个二维图像，这个操作相当于将图像转过半圈，使原本位于左上角的元素移到右下角，右下角的元素移到左上角，以此类推。
* 中心对称
* 1 2 3    9 8 7
* 4 5 6    6 5 4
* 7 8 9    3 2 1
*
*实现思路
对于任意矩阵元素 matrix[i][j]，在旋转 180° 后，它会移动到新的位置 matrix[n-1-i][n-1-j]。
* 直接将矩阵从中心对称翻转。
*
* 具体算法
遍历矩阵的前半部分，对于每个元素 matrix[i][j]，将其与 matrix[n-1-i][n-1-j] 交换。
通过对称交换完成整个矩阵的 180° 旋转。
* */

#include <stdio.h>

void rotate180(int matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 找到对称位置 (n-1-i, n-1-j)
            if (i < n - 1 - i || (i == n - 1 - i && j < n - 1 - j)) {
                // 交换 matrix[i][j] 和 matrix[n-1-i][n-1-j]
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = temp;
            }
        }
    }
}

void printMatrix(int matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 3;
    int matrix[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("原矩阵:\n");
    printMatrix(matrix, n);

    rotate180(matrix, n);

    printf("\n旋转180°后的矩阵:\n");
    printMatrix(matrix, n);

    return 0;
}
