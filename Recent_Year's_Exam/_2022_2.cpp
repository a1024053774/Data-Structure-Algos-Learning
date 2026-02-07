//
// Created by 10240 on 2024/10/31.
//

//2022 T2

//给定一个二维数组A[i][j],找出二维数组的鞍点
//在该元素所在的行中，这个元素是最大的元素
// 在该元素所在的列中，这个元素是最小的元素

// 外层循环通常控制行
// 内层循环通常控制列


//先找每行的最大值

//再找每列的最小值
#include <iostream>

void find(int A[][], int m,int n){
    for(int i = 0;i < m;i++){//一行一行处理
        int max_hang = A[i][0];//先将最大值赋给该行第一个元素
        int max_lie_num = 0;//最大值的列号
        for(int j = 1;j< n;j++){//遍历该行
            if(A[i][j] > max_hang){
                max_value = A[i][j];
                max_lie_num = j;//记录最大值所在第几列
            }
        }

        //检查这个最大值是否是所在列的最小值
        bool is_Find = true;//若不是，修改该值
        for(int k = 0;k < m;k++){//遍历该列
            if(A[k][max_lie_num] < max_value){
                //不是最小
                is_Find = false;
                break;
            }
        }

        if(is_Find){
            //如果为true
            cout << "鞍点：" <<max_value <<"所在行"<<i<<"所在列"<<max_lie_num;
        }
    }
}
