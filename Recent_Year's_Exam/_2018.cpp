//
// Created by 10240 on 2024/10/22.
//

//2018真题
//已知两个有序表A[0...n-1]和B[0...m-1],试写一算法，归并为有序表C[0...m+n-1]
// 修正后的代码
void Merge(int A[], int B[], int n, int m, int C[]) {
    int i = 0, j = 0, k = 0;

    // 比较A和B的元素，将较小者放入C
    while(i < n && j < m) {
        if(A[i] < B[j]) {
            C[k] = A[i];
            i++;
            k++;
        } else {
            C[k] = B[j];
            j++;
            k++;
        }
    }

    // 将A中剩余元素复制到C
    while(i < n) {
        C[k] = A[i];
        i++;
        k++;
    }

    // 将B中剩余元素复制到C
    while(j < m) {
        C[k] = B[j];
        j++;
        k++;
    }
}