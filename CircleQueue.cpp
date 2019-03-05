#include<iostream>
#include<stdio.h>
#include<string.h>
# define MAXSIZE 50
template<typename T>
class Sequeue{
	public:
		Sequeue();
		bool isEmpty();
		bool isFull();
		bool EnterQueue(T x);  //入队 
		bool DelQueue(T &x);    //出队 
		int size();
private:
	T data[MAXSIZE];
	int rear;
	int length;
	
};


template<typename T>
Sequeue<T>::Sequeue()
{
	rear = 0;
	length = 0;
}
template<typename T>
bool Sequeue<T>::isEmpty()
{
	return length==0;	
}
template<typename T>
bool Sequeue<T>::isFull()
{
	return length==MAXSIZE;
}
template<typename T>
bool Sequeue<T>::EnterQueue(T x)
{
	if(isFull())
		return false;
	
	data[rear]=x;
	rear = (rear+1)%MAXSIZE;
	length++;
	return true;
}
template<typename T>
bool Sequeue<T>::DelQueue(T &x)
{
	if(isEmpty())
	return false;
	
	x = data[(rear-length+1+MAXSIZE)%MAXSIZE];
	length--;
	
	return true;
}

template<typename T>
int Sequeue<T>::size()
{
	return length;
}





int main(int argc,char *argv[])
{
	
	 Sequeue<int> *Queue;
	 Queue = new Sequeue<int>;
	 
	
	return 0;
}
