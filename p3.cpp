#include <iostream>
using namespace std;

struct Node
{
	int address;
	int data;
};

void swapNode(Node N[],int i,int j)
{
	int a = N[i].address;
	int d = N[i].data;
	N[i].address = N[j].address;
	N[i].data = N[j].data;
	N[j].address = a;
	N[j].data = d;
}
int main()
{
	int head;
	int n, k;
	cin >> head >> n >> k;
	Node N1[100000];
	
	//input
	for (int i = 0; i < n; i++)
	{
		int index;
		cin >> index;
		cin >> N1[index].data >> N1[index].address ;
	}
	//link
	Node* N2 = new Node[n];
	N2[0].address = head;
	N2[0].data = N1[head].data;
	for (int i = 1; i < n; i++)
	{
		N2[i].address = N1[N2[i - 1].address].address;
		N2[i].data = N1[N2[i].address].data;
	}
	
	//reverse
	//k=0?
	if (k != 0&&k!=1)
	{
		int times = n / k;
		for (int i = 0; i < times; i++)
		{
			int mid = (2 * i + 1)*k / 2;
			for (int j = k * i; j < mid; j++)
			{
				swapNode(N2, j, k - 1 - j);
			}
		}
	}
	
	
	
	int i;
	for ( i = 0; i < n-1; i++)
	{
		cout << N2[i].address << " " << N2[i].data << " "<< N2[i+1].address<< endl;
	}
	cout << N2[i].address << " " << N2[i].data << "  -1" << endl;
	delete[] N2;
	return 0;
}

