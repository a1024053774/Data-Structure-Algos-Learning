//
// Created by 10240 on 2024/11/27.
//
//2024_T4
/*
二维数组由0和1组成，且每行每列保持依次递增。求某二维数组“0”的个数,要求时间复杂度为O（n)。

如 arr = [ ]
第一行0 0 0 0 1
第二行0 0 1 1 1
第三行0 0 1 1 1
第四行1 1 1 1 1
第五行1 1 1 1 1

输出：8

*/

#include <iostream>
/*
 * arr: 二维数组
 * rows: 行数
 * cols: 列数
 * 返回值: 0的个数
 */
int countZeros(int arr[][], int rows, int cols) {
    int count = 0;
    int row = 0;           // 从第一行开始
    int col = cols - 1;    // 从最后一列开始

    // 从右上角开始遍历
    while (row < rows && col >= 0) {
        if (arr[row][col] == 1) {
            // 如果当前位置是1，则这一列上面的都已经计算过
            // 向左移动一列
            col--;
        } else {  // arr[row][col] == 0
            // 如果当前位置是0，则这一行左边的都是0
            // 计数加上当前位置及左边的0的个数
            count += (col + 1);
            // 向下移动一行
            row++;
        }
    }

    return count;
}