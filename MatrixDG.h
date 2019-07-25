#pragma once
#include<iostream>
using namespace std;
#define MAXNODE 100
#define INF ~(1<<31)


class EData {
public:
	EData(char s, char e, int w) :
		start(s), end(e), weight(w) {}
	friend class MatrixDG;
private:
	char start;
	char end;
	int weight;
};
//单向链接表图

class MatrixDG {
public:
	MatrixDG();
	MatrixDG(char v[], int vlen, EData *e[], int elen);
	void print();

	void DFS(int i, char *visited);
	void DFS();
	void BFS();
	void dijkstra(int vs, int prep[], int dist[]);
private:
	char Ele[MAXNODE];

	int VNodeNum;
	int EEdgeNum;
	int Matrix[MAXNODE][MAXNODE];
	int getposition(char c);
	char readData();
};

MatrixDG::MatrixDG()
{
	char c1, c2;
	int P1, P2;
	int weight;
	for (int i = 0;i < MAXNODE;++i)
		for (int j = 0;j < MAXNODE;++j)
		{
			if(i==j)
				Matrix[i][j] = 0;
			else
				Matrix[i][j] = INF;
		}
			

	cout << "input graph node number:";
	cin >> VNodeNum;
	cout << "input graph edge number";
	cin >> EEdgeNum;

	if (VNodeNum < 0 || EEdgeNum<0 || EEdgeNum>VNodeNum*(VNodeNum - 1))
	{
		cout << "create graph error" << endl;
		return;
	}

	for (int i = 0;i < VNodeNum;++i)
	{
		Ele[i] = readData();
	}

	for (int i = 0;i < EEdgeNum;++i)
	{
		c1 = readData();
		c2 = readData();
		if (c1 == c2)
		{
			cout << "graph has same node error" << endl;
			return;
		}
		cout << "input weights of " << c1 << "->" << c2 << ": ";
		cin >> weight;
		P1 = getposition(c1);
		P2 = getposition(c2);
		Matrix[P1][P2] = weight;
		Matrix[P2][P1] = weight;
	}

}
MatrixDG::MatrixDG(char v[], int vlen, EData *e[], int elen)
{
	if (vlen < 0 || elen<0 || elen>vlen*(vlen - 1))
	{
		cout << "create graph error" << endl;
		return;
	}
	for (int i = 0;i < MAXNODE;++i)
		for (int j = 0;j < MAXNODE;++j)
		{
			if (i == j)
				Matrix[i][j] = 0;
			else
				Matrix[i][j] = INF;
		}

	char c1, c2;
	int P1, P2;
	VNodeNum = vlen;
	EEdgeNum = elen;
	for (int i = 0;i < VNodeNum;++i)
		Ele[i] = v[i];

	for (int j = 0;j < EEdgeNum;++j)
	{
		c1 = e[j]->start;
		c2 = e[j]->end;
		if (c1 == c2)
		{
			cout << "graph has same node error" << endl;
			return;
		}
		P1 = getposition(c1);
		P2 = getposition(c2);
		Matrix[P1][P2] = e[j]->weight;
		Matrix[P2][P1] = e[j]->weight;
	}
}

void MatrixDG::print()
{
	
	cout << "matrix graph" << endl;
	for (int i = 0;i < VNodeNum;++i)
	{
		printf("Node index[%d] (%c)", i, Ele[i]);
		for (int j = 0;j < VNodeNum;++j)
		{
			if (Matrix[i][j]!=INF)
			{
				cout << "->" << Ele[j];
			}
		}
		cout << endl;
	}
}

int MatrixDG::getposition(char c)
{
	for(int i = 0;i<VNodeNum;++i)
	{
		if (c == Ele[i])
			return i;
	}
	return -1;
}


char MatrixDG::readData()
{
	char ch;
	do {
		cin >> ch;
	} while (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'));

	return ch;
}

void MatrixDG::DFS(int i, char *visited)
{
	if (visited[i] != 1)
	{
		visited[i] = 1;
		cout << Ele[i] << "->";
		for (int j = 0;j < VNodeNum;++j)
		{
			if (Matrix[i][j]!=1)
				continue;
			DFS(j, visited);
		}
	}

}


void MatrixDG::DFS()
{
	cout << "深度优先遍历: ";
	char visited[MAXNODE];
	memset(visited, 0, sizeof(char)*MAXNODE);
	for (int i = 0;i < VNodeNum;++i)
	{
		DFS(i, visited);
	}
	cout << endl;
}
void MatrixDG::BFS()
{
	int rear = 0;
	int head = 0;
	int k;
	int queue[MAXNODE];
	char visited[MAXNODE];
	cout << "广度优先遍历: ";
	memset(visited, 0, sizeof(char)*MAXNODE);
	for (int i = 0; i < VNodeNum; ++i)
	{
		if (visited[i] == 1)
			continue;

		visited[i] = 1;
		cout << Ele[i] << "->";
		queue[rear++] = i;
		while (rear != head)
		{
			k = queue[head++];
			for (int j = 0;j < VNodeNum;++j)
			{
				if (j == k || Matrix[k][j]!=1)
					continue;

				if (visited[j] != 1)
				{
					visited[j] = 1;
					cout << Ele[j] << "->";
					queue[rear++] = j;
				}
			}
		}

	}
	cout << endl;
}

void MatrixDG::dijkstra(int vs, int prep[], int dist[])
{
	int i, j, k;
	int min, temp;
	int flag[MAXNODE];

	for (i = 0;i < VNodeNum;++i)
	{
		flag[i] = 0;
		prep[i] = vs;
		dist[i] = Matrix[vs][i];
	}

	flag[vs] = 1;
	dist[vs] = 0;
	
	for (j = 0;j < VNodeNum;++j)
	{
		min = INF;
		for (i = 0;i < VNodeNum;++i)
		{
			if (flag[i] == 0 && dist[i] < min)
			{
				min = dist[i];
				k = i;
			}
		}
		flag[k] = 1;
		for (i = 0;i < VNodeNum;++i)
		{
			if (flag[i] == 0)
			{
				temp = Matrix[k][i];
				temp = (temp == INF) ? INF : (min + temp);
				if (temp < dist[i])
				{
					dist[i] = temp;
					prep[i] = k;
				}
			}
		}
	}
	
	for (i = 0;i < VNodeNum;++i)
	{
		cout << Ele[vs] << "->" << Ele[i]<< " " << dist[i] << endl;
	}
}
