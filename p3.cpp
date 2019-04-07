// p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Node1
{
	string address;
	int data;
	string next;
};
struct Node2
{
	string address;
	int data;
};
int main()
{
	freopen("in.txt", "r", stdin);
	string head;
	int n, k;
	cin >> head >> n >> k;
	Node1* N1 = new Node1[n];
	vector<Node1> vc;
	int h = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> N1[i].address >> N1[i].data >> N1[i].next;
		if (N1[i].address == head)
			h = i;
	}
	vc.push_back(N1[h]);
	string address = N1[h].next;
	while (address!="-1")
	{
		for (int i = 0; i < n; i++)
		{
			if (N1[i].address == address)
			{
				vc.push_back(N1[i]);
				address = N1[i].next;
				break;
			}
		}
	}
	if (n >= k)
	{
		int times = n / k;
		for (int i = 0; i < times; i++)
		{
			reverse(&vc.at(i*k), &vc.at((i + 1)*k));
		}
	}
	
	int i;
	for ( i = 0; i < n-1; i++)
	{
		cout << vc[i].address << " " << vc[i].data << " " << vc[i+1].address<< endl;
	}
	cout << vc[i].address << " " << vc[i].data << " " << vc[i].next << endl;
	return 0;
}

