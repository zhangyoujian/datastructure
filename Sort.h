#pragma once
#include<memory>
//�㷨���Ӷ�ΪO(N^2)������
void BubbleSort(int A[], int N);
void SelectSort(int A[], int N);
void InsertSort(int A[], int N);


//�㷨���Ӷ�ΪO(N*Log(N))������
void MergeSort(int A[], int N);
void QuickSort(int A[], int p, int q);

//�㷨���Ӷ�ΪO(N)������
void CountSort(int A[], int N);
void BaseSort(int A[], int N);
