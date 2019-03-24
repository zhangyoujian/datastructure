#pragma once
#include<memory>
//算法复杂度为O(N^2)的排序
void BubbleSort(int A[], int N);
void SelectSort(int A[], int N);
void InsertSort(int A[], int N);


//算法复杂度为O(N*Log(N))的排序
void MergeSort(int A[], int N);
void QuickSort(int A[], int p, int q);

//算法复杂度为O(N)的排序
void CountSort(int A[], int N);
void BaseSort(int A[], int N);
