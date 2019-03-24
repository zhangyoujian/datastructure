#include"Sort.h"
//算法复杂度为O(N^2)的排序
void BubbleSort(int A[], int N)
{
	int temp;
	for(int i = 0;i<N-1;i++)
		for (int j = 0;j<N-1-i;j++)
		{
			if (A[j + 1] < A[j])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
}
void SelectSort(int A[], int N)
{
	int temp;
	for(int i = 0;i<N-1;i++)
		for (int j = i + 1;j < N;j++)
		{
			if (A[j] < A[i])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;

			}
		}
}
void InsertSort(int A[], int N)
{
	int start;
	for (int i = 0;i < N-1;i++)
	{
		start = A[i+1];
		for (int j = i;j >=0;j--)
		{
			if (A[j] > start)
			{
				A[j+1] = A[j];
				A[j] = start;
			}
			
		}
	}
}

//算法复杂度为O(N*Log(N))的排序
void MergeSort(int A[], int N)
{
	if (N <= 1)
		return;
	int mid = N / 2 + (N % 2 == 0 ? 0 : 1);

	int *p = new int[mid];
	int *q = new int[N - mid];
	memcpy(p, A, sizeof(int)*(mid));
	memcpy(q, A + mid, sizeof(int)*(N - mid));
	MergeSort(p, mid);
	MergeSort(q, N - mid);

	int i = 0, j = 0,k=0;
	while (i < mid && j < (N - mid))
	{
		if (p[i] < q[j])
		{
			A[k] = p[i];
			i++;
			k++;
		}
		else 
		{
			A[k] = q[j];
			j++;
			k++;
		}
	}

	while (i < mid)
	{
		A[k] = p[i];
		i++;
		k++;
	}
	while (j < (N - mid))
	{
		A[k] = q[j];
		j++;
		k++;
	}

	delete[] p;
	delete[] q;
}
void QuickSort(int A[], int p, int q)
{
	int X = A[p];
	int i = p;
	int j = p+1;
	int temp;
	if (p >= q)
		return;
	while (j < q)
	{
		if (A[j] <= X)
		{
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			
		}
		j++;
	}
	temp = A[p];
	A[p] = A[i];
	A[i] = temp;
	p = i;
	QuickSort(A, 0, p);
	QuickSort(A, p+1, q);
}

//算法复杂度为O(N)的排序
void CountSort(int A[], int N)
{
	int min = A[0];
	int max = A[0];

	for (int i = 0;i < N;i++)
	{
		if (A[i] < min)
			min = A[i];
		if (A[i] > max)
			max = A[i];
	}
	int *C = new int[max - min + 1];
	memset(C, 0, sizeof(int)*(max - min + 1));
	for (int i = 0;i < N;i++)
	{
		C[A[i] - min]++;
	}
	for (int i = 1;i < max - min + 1;i++)
	{
		C[i] = C[i - 1] + C[i];
	}

	int *B = new int[N];
	for (int i = N - 1;i >= 0;i--)
	{
		B[C[A[i]-min]-1] = A[i];
		C[A[i]-min]--;
	}

	memcpy(A, B, sizeof(int)*N);
	delete[] C;
	delete[] B;
}


void BaseSort(int A[], int N)
{
	int *col = new int[N];
	for (int i = 0;i < N;i++)
	{
		col[i] = A[i] % 10;
	}

}