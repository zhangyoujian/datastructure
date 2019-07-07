#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;



//—°‘Ò≈≈–ÚO(N2)
template<class T>
void SelectSort(T *arr, int N)
{
	if(arr==NULL || N<=1)
		return;
	
	for(int i= 0;i<N-1;i++)
	for(int j = i+1;j<N;j++)
	{
		if(arr[j]<arr[i])
		{
			T temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
}



//√∞≈›≈≈–ÚO(N2)
template<class T>
void BubbleSort(T *arr, int N)
{
	if(arr==NULL || N<=1)
		return;
	
	for(int i= 0; i<N-1; i++)
	for(int j = 0; j<N-i-1; j++)
	{
		if(arr[j+1]<arr[j])
		{
			T temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
		}
	}
}



//≤Â»Î≈≈–ÚO(N2)
template<class T>
void InsertSort(T *arr, int N)
{
	if(arr==NULL || N <= 1)
		return;
	
	for(int i = 0;i<N-1;i++)
	{
		T x = arr[i+1];
		int j = i;
		while((j>=0)&& (arr[j+1]<arr[j]))
		{
			arr[j+1] = arr[j];
			arr[j] =x;
			j--;
		}
	}
}



//øÏÀŸ≈≈–ÚO(Nlog(N))
template<class T>
void QuickSort(T *arr, int begin, int end)
{
	if(begin>=end)
		return;
	
	int i = begin+1;
	int j = begin;
	T X = arr[j];
	
	for(;i<=end;++i)
	{
		if(arr[i]<=X)
		{
			j++;
			if(j!=i)	
			{
				T temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
	T temp =arr[begin];
	arr[begin] = arr[j];
	arr[j] = temp;
	
	QuickSort(arr,begin,j-1);
	QuickSort(arr,j+1,end);
}




//ÀÊª˙øÏÀŸ≈≈–ÚO(Nlog(N))
template<class T>
int Partion(T *arr,int length, int begin, int end)
{
	if(arr==NULL || length<=0 || begin<0 || end>length-1)
		return -1;
	
	srand((unsigned int)(time(0)));
	int index = rand()%(end-begin+1) + begin;
	T X = arr[index];
	
	T temp = arr[index];
	arr[index] = arr[begin];
	arr[begin] = temp;
	
	
	int j = begin;
	for(int i = begin+1;i<=end;++i)
	{
		if(arr[i]<X)
		{
			j++;
			if(j!=i)
			{
			  temp= arr[j];
		      arr[j] = arr[i];
		      arr[i] = temp;
			}
		}
	}
	
	temp= arr[begin];
    arr[begin] = arr[j];
    arr[j] = temp;
    return j;	
}

template<class T>
void RandomQuickSort(T *arr, int length,int begin, int end)
{
	if(begin>=end)
		return;
	
	int small = Partion(arr,length,begin,end);
	if(small>begin)
		RandomQuickSort(arr,length,begin,small-1);
	if(small<end)
		RandomQuickSort(arr,length,small+1,end);
}



//πÈ≤¢≈≈–ÚO(Nlog(N))
 template<class T>
void MergeSort(T *arr, int N)
{
	if(arr==NULL || N<=1)
		return;
	
	int mid= N/2+(N%2==0?0:1);
	
	T *LBuffer = new T[mid];
	T *RBuffer = new T[N-mid];
	
	memcpy(LBuffer,arr,sizeof(T)*(mid));
	memcpy(RBuffer,arr+mid,sizeof(T)*(N-mid));
	
	MergeSort(LBuffer,mid);
	MergeSort(RBuffer,N-mid);
	
	
	int left = 0;
	int right = 0;
	int index = 0;
	
	while((left<mid) && right<(N-mid))
	{
		if(LBuffer[left]<RBuffer[right])
		{
			arr[index++] = LBuffer[left++];
		}
		else
		{
			arr[index++] = RBuffer[right++];
		}
	}
	
	while(left<mid)
	{
		arr[index++] = LBuffer[left++];
	}
	while(right<(N-mid))
	{
		arr[index++] = RBuffer[right++];
	}
	
	delete[] LBuffer;
	delete[] RBuffer;
}


//œ£∂˚≈≈–Ú O(Nlog(N)) 
 template<class T>
void ShellInsert(T *arr, int N, int begin, int gap)
{
	for(int i = begin; i<N;i+=gap)
	{
		if(i+gap>N-1)
	    	break;
	    	
	   	int j = i;
	    T x = arr[j+gap];
	    while((j>=0) && (arr[j+gap]<arr[j]))
	    {
	    	arr[j+gap] = arr[j];
	    	arr[j] = x;
	    	j-=gap;
		}
		
	}
}
 template<class T>
void ShellSort(T *arr, int N)
{
	if(arr==NULL || N<=1)
		return;
	
	int gap;
	for(gap = N/2; gap>0;gap/=2)
	{
		for(int i = 0;i<gap;++i)
		{
			ShellInsert(arr, N, i,gap);
		}
	}
}


//∂—≈≈–Ú   O(Nlog(N)) 
template<class T>
void HeapDown(T *arr, int begin, int end)
{
	int c = begin;
	T temp = arr[c];
	int i = 2 * begin + 1;

	for (;i <= end;c = i, i = 2 * i + 1)
	{
		if (i < end && (arr[i] < arr[i + 1]))
			i++;
		if (temp >= arr[i])
			break;
		else
		{
			arr[c] = arr[i];
			arr[i] = temp;
		}
	}
}
template<class T>
void HeapSort(T *arr, int N)
{
	if (arr == NULL || N <= 1)
		return;
	T temp;
	for (int i = N / 2 - 1; i >= 0;i--)
		HeapDown(arr, i, N - 1);  //≥ı ºªØ∂˛≤Ê∂—

	for (int j = N - 1;j >0;--j)
	{
		temp = arr[0];
		arr[0] = arr[j];
		arr[j] = temp;
		HeapDown(arr, 0, j-1);
	}
}


//Õ∞≈≈–Ú”÷ O(N)
template<class T>
void BucketSort(T *arr, int N, int MAX)
{
	T *Bucket = new T[MAX];
	memset(Bucket, 0, sizeof(T)*MAX);

	for (int i = 0;i < N;++i)
		Bucket[arr[i]]++;
	int j = 0;
	for (int i = 0, j=0 ; i < MAX; ++i)
	{
		while ((Bucket[i]--) > 0)
			arr[j++] = i;
	}
	delete[] Bucket;
}
 


//ª˘ ˝≈≈–Ú  O(N+K)
template<class T>
T get_max(T arr[], int N)
{
	if (arr == NULL || N < 1)
		std::exception(" ˝◊È≤ªƒ‹Œ™ø’");
	T temp = arr[0];
	for (int i = 1;i < N;i++)
	{
		if (arr[i] > temp)
			temp = arr[i];
	}
	return temp;
}

template<class T>
void Count_Sort(T *arr, int N, int exp)
{
	T *Bucket = new T[10];
	T *Output = new T[N];
	memset(Bucket, 0 ,sizeof(T) * 10);
	for (int i = 0; i < N;i++)
		Bucket[ (arr[i] / exp) %10 ]++;

	for (int i = 1; i < 10;++i)
		Bucket[i] += Bucket[i - 1] ;

	for (int i = N - 1;i >= 0;--i)
	{
		Output[Bucket[ (arr[i] / exp) % 10]-1] = arr[i];
		Bucket[ (arr[i] / exp) % 10]--;
	}

	memcpy(arr, Output, sizeof(T)*N);
	delete[] Bucket;
	delete[] Output;
}

template<class T>
void BaseSort(T arr[], int N)
{
	T maxNumVar = get_max(arr, N);
	for (int exp=1; maxNumVar/exp > 0; exp *= 10)
	{
		Count_Sort(arr, N, exp);
	}
}


//º∆ ˝≈≈–Ú O(N)
template<class T>
void CountSort(T arr[], int N, int K)
{
	if (arr == NULL || N <= 1 || K<=0)
		return;

	T minVal = arr[0];
	for (int i = 1;i < N;++i)
	{
		if (arr[i] < minVal)
			minVal = arr[i];
	}

	T *B = new T[N];
	T *C = new T[K-minVal+1];

	memset(C,  0,  sizeof(T)*(K - minVal + 1));
	for (int i = 0;i < N;++i)
		C[arr[i] - minVal]++;

	for (int i = 1 ; i < K - minVal + 1;i++)
		C[i] += C[i - 1];

	for (int i = N - 1;i >= 0;--i)
	{
		B[C[arr[i] - minVal] - 1] = arr[i];
		C[arr[i] - minVal]--;
	}

	memcpy(arr, B, sizeof(T)*N);
	delete[] B;
	delete[] C;
}

