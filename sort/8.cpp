#include <bits/stdc++.h>
using namespace std;
void fun(int A[], int low, int mid, int high)
{
  int *B = new int[high - low + 1];
  int i = low, j = mid + 1;
  for (int c = low; c <= high; ++c)
    B[c] = A[c];

  int k;
  for(k = low; i <= mid && j <= high; ++k)
    if(B[i] <= B[j])
      A[k] = B[i++];
    else
      A[k] = B[j++];
  }

  while (i <= mid){
    A[k++] = B[i++];}
  while (j <= high){
    A[k++] = B[j++];}
}
void MergeSort(int A[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    MergeSort(A, low, mid);
    MergeSort(A, mid + 1, high);
    fun(A, low, mid, high);
  }
}
int main()
{
  int A[] = {12, 6, 9, 2, 4};
  MergeSort(A, 0, 4);
  for (int i = 0; i < 5; i++)
  {
    cout << A[i] << ' ';
  }
  return 0;
}