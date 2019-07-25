#pragma once
#include<iostream>
using namespace std;

#define MAXNODE 100
#define INF ~(0x01<<31)
#define NEGINF (0x01<<31)

class EData {
public:
	EData(char s, char e, int w) :
		start(s), end(e), weight(w)
	{

	}
	friend class ListDG;
private:
	char start;
	char end;
	int weight;

};

//单向链接表图
class ListDG {
	class ENode {
	public:
		int vdex;
		int weight;
		ENode *nextNode;
	};

	class VNode {
	public:
		char data;
		ENode *firstNode;
	};

public:
	ListDG();
	ListDG(char vnode[], int vlen, EData *enode[], int elen);
	~ListDG();

	void DFS(int i, char *visited);
	void DFS();
	void BFS();
	void dijkstra(int vs, int prep[], int dist[]);
	void print();
private:
	int getWeight(int start, int end);
	char readdata();
	int getposition(char ch);
	void LinkLast(ENode *start, ENode* node);
	VNode Ele[MAXNODE];
	int VnodeNum;
	int EdgeNum;

};


ListDG::ListDG()
{
	char c1, c2;
	int p1, p2;
	int weight;
	ENode *node2;
	ENode *node1;

	cout << "input graph node number:";
	cin >> VnodeNum;
	cout << "input graph edge number:";
	cin >> EdgeNum;

	if (VnodeNum < 0 || EdgeNum<0 || EdgeNum>VnodeNum*(VnodeNum - 1))
		std::exception("create graph eror");

	for (int i = 0;i < VnodeNum;++i)
	{
		c1 = readdata();
		Ele[i].data = c1;
		Ele[i].firstNode = NULL;
	}

	for (int i = 0;i < EdgeNum;++i)
	{
		c1 = readdata();
		c2 = readdata();

		if (c1 == c2)
		{
			cout << "input same Graph Node Error" << endl;
			return;
		}
		cout << "input weights of " << c1 << "->" << c2 << ": ";
		cin >> weight;
		p1 = getposition(c1);
		p2 = getposition(c2);
		node2 = new ENode();
		node2->vdex = p2;
		node2->weight = weight;
		node2->nextNode = NULL;
		if (Ele[p1].firstNode == NULL)
			Ele[p1].firstNode = node2;
		else
			LinkLast(Ele[p1].firstNode, node2);

		node1 = new ENode();
		node1->vdex = p1;
		node1->weight = weight;
		node1->nextNode = NULL;
		if (Ele[p2].firstNode == NULL)
			Ele[p2].firstNode = node1;
		else
			LinkLast(Ele[p2].firstNode, node1);
	}

}
ListDG::ListDG(char vnode[], int vlen, EData *enode[], int elen)
{
	if (vnode == NULL || vlen <= 0 || enode == NULL || elen <= 0 || vlen > elen*(elen - 1))
	{
		std::exception("create graph error");
		return;
	}
	VnodeNum = vlen;
	EdgeNum = elen;
	for (int i = 0;i < VnodeNum;++i)
	{
		Ele[i].data = vnode[i];
		Ele[i].firstNode = NULL;
	}

	for (int j = 0;j < EdgeNum;++j)
	{
		char c1 = enode[j]->start;
		char c2 = enode[j]->end;

		if (c1 == c2)
		{
			cout << "graph occure same Node ";
			return;
		}

		int index1 = getposition(c1);
		int index2 = getposition(c2);
		if (index1 == -1 || index2 == -1)
			std::exception("initial edge error");

		ENode *P2 = new ENode();
		P2->vdex = index2;
		P2->weight = enode[j]->weight;
		P2->nextNode = NULL;
		if (Ele[index1].firstNode == NULL)
			Ele[index1].firstNode = P2;
		else
			LinkLast(Ele[index1].firstNode, P2);

		ENode *P1 = new ENode();
		P1->vdex = index1;
		P1->weight = enode[j]->weight;
		P1->nextNode = NULL;
		if (Ele[index2].firstNode == NULL)
			Ele[index2].firstNode = P1;
		else
			LinkLast(Ele[index2].firstNode, P1);

	}
}
ListDG::~ListDG()
{

}

char ListDG::readdata()
{
	char ch;
	do {
		cin >> ch;
	} while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
	return ch;
}
int ListDG::getposition(char ch)
{
	for (int i = 0;i < VnodeNum;++i)
	{
		if (Ele[i].data == ch)
			return i;
	}
	return -1;
}

void ListDG::LinkLast(ENode *start, ENode* node)
{
	ENode *P = start;
	while (P->nextNode != NULL)
		P = P->nextNode;
	P->nextNode = node;
}


void ListDG::print()
{
	cout << "list graph" << endl;
	for (int i = 0;i < VnodeNum;++i)
	{
		printf("Node index[%d] (%c)", i, Ele[i].data);
		ENode *P = Ele[i].firstNode;
		while (P != NULL)
		{
			printf("->%c", Ele[P->vdex].data);
			P = P->nextNode;
		}
		cout << endl;
	}

}

void ListDG::DFS(int i, char *visited)
{
	ENode* node = NULL;
	if (visited[i] != 1)
	{
		visited[i] = 1;
		cout << Ele[i].data<<"->" ;
		node = Ele[i].firstNode;
		while (node)
		{
			DFS(node->vdex, visited);
			node = node->nextNode;
		}
	}
}

void ListDG::DFS()
{
	cout << "深度优先遍历:";
	char visited[MAXNODE];
	memset(visited, 0, sizeof(char)*MAXNODE);

	for (int i = 0;i < VnodeNum;++i)
	{
		DFS(i, visited);
	}
	cout << endl;
}
void ListDG::BFS()
{
	cout << "广度优先遍历:";
	int rear = 0;
	int head = 0;
	int queue[MAXNODE];
	char visited[MAXNODE];
	memset(visited, 0, sizeof(char)*MAXNODE);
	ENode *node = NULL;

	for (int i = 0;i < VnodeNum;++i)
	{
		if (visited[i] != 1)
		{
			visited[i] = 1;
			queue[rear++] = i;
			cout << Ele[i].data<<"->";
			while (head != rear)
			{
				node = Ele[queue[head++]].firstNode;
				while (node)
				{
					if (visited[node->vdex] != 1)
					{
						visited[node->vdex] = 1;
						queue[rear++] = node->vdex;
						cout << Ele[node->vdex].data << "->";
					}
					node = node->nextNode;
				}
			}
		}
	}
	cout << endl;
}

int ListDG::getWeight(int start, int end)
{
	if (start == end)
		return 0;

	ENode *node = Ele[start].firstNode;
	while (node)
	{
		if (node->vdex == end)
			return node->weight;
		node = node->nextNode;
	}
	return INF;
}

void ListDG::dijkstra(int vs, int prep[], int dist[])
{
	int i, j, k;
	int flag[MAXNODE];
	int min=INF;
	int temp;
	for (i = 0;i < VnodeNum;++i)
	{
		prep[i] = vs;
		dist[i] = getWeight(vs, i);
		flag[i] = 0;
	}
	dist[vs] = 0;
	flag[vs] = 1;

	for (j = 0;j < VnodeNum;++j)
	{
		min = INF;
		for (i = 0;i < VnodeNum; ++i)
		{
			if (flag[i] == 0 && (dist[i]<min))
			{
				k = i;
				min = dist[i];
			}
		}
		flag[k] = 1;
		//更新所有路径
		for (i = 0;i < VnodeNum;++i)
		{
			if (flag[i] == 0)
			{
				temp = getWeight(k,i);
				temp = (temp == INF) ? INF : (temp + min);
				if (temp < dist[i])
				{
					dist[i] = temp;
					prep[i] = k;
				}
			}
		}
	}
	for (i = 0;i < VnodeNum;++i)
	{
		cout << Ele[vs].data << "->" << Ele[i].data << " " << dist[i] << endl;
	}
}