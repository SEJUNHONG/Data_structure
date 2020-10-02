// HW3_È«¼¼ÁØ_2015706035
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void print1(vector<char> v, int index, int depth)
{
	if (v[0] != NULL)
	{
		if(2*index+2<v.size())
			print1(v, 2 * index + 2, depth + 1);
		cout << setw(2 * depth) << "" << v[index] << endl;
		if(2*index+1<v.size())
			print1(v, 2 * index + 1, depth + 1);
	}
}

void print2(vector<char> v, int index, int depth)
{
	int i = 0;
	int n = 0;
	int m = (int) (log2(v.size()));
	
	int before = 0;

	if (v[0] != NULL)
	{
		for (int index = 0; index < v.size(); index++)
		{
			int k = i;
			n = pow(2, i);
			if ((index-before) % n == 0) 
			{
				for (int p = 0; p < pow(2, m-k) - 1; p++)
					cout << " ";
				cout << v[index];
				before = index;
				i++;
				for (int p = 0; p < pow(2, m-k); p++)
					cout << " ";
				cout << endl;
			}
			else
			{
				for (int p = 0; p < pow(2, m-k) - 1; p++)
					cout << " ";
				cout << v[index];
				for (int p = 0; p < pow(2, m-k); p++)
					cout << " ";
			}
		}
	}
}

char H_tree[15][15] = { {0} };

void H(int node, int i, int j, int d, int U, int D, int R, int L, vector<char> v, int n)
{
	int V[4][2] = { { -1, 0 },{ 1, 0 },{ 0, 1 },{ 0, -1 } };
	if (node > n) 
		return;
	H_tree[i][j] = v[node - 1];
	if (2 * node <= n)
	{
		H_tree[i + d * V[L][0]][j + d * V[L][1]] = v[2 * node - 1];
		H(4 * node, i + d * (V[L][0] + V[U][0]),
			j + d * (V[L][1] + V[U][1]), d / 2, D, U, L, R, v, n);
		H(4 * node + 1, i + d * (V[L][0] + V[D][0]),
			j + d * (V[L][1] + V[D][1]), d / 2, U, D, R, L, v, n);
	}
	if (2 * node + 1 <= n)
	{
		H_tree[i + d * V[R][0]][j + d * V[R][1]] = v[2 * node];
		H(4 * node + 2, i + d * (V[R][0] + V[D][0]),
			j + d * (V[R][1] + V[D][1]), d / 2, U, D, R, L, v, n);
		H(4 * node + 3, i + d * (V[R][0] + V[U][0]),
			j + d * (V[R][1] + V[U][1]), d / 2, D, U, L, R, v, n);
	}
}

int Center(int n)
{
	return n <= 1 ? 0 : 2 * Center(n / 4) + 1;
}

int Depth(int n)
{
	return n <= 7 ? 1 : 2 * Depth(n / 4);
}

int main()
{
	string ins = "INS";
	char a;
	vector<char> v;
	string del = "DEL ";
	string eoi = "EOI";
	int index = 0;
	int depth = 0;
	make_heap(v.begin(), v.end());

	cout << "ÀÔ·Â : ";
	while (ins != "EOI")
	{
		cin >> ins;
		if (ins == "INS")
		{
			cin >> a;
			v.push_back(a);
			push_heap(v.begin(), v.end());
		}
		else if (ins == "DEL")
		{
			pop_heap(v.begin(), v.end());
			v.pop_back();
		}
	}
	cout << endl;
	cout << "Heap : ";
	for(int i=0; i<v.size(); i++)
		cout << v[i];
	cout << "\n" << endl;

	depth = 1;
	cout << "1. rotated form" << endl;
	print1(v, 0, depth);
	cout << "\n" << endl;

	depth = v.size() - 1;
	cout << "2. not-rotated form" << endl;
	print2(v, 0, depth);
	cout << "\n" << endl;

	int n = v.size();

	cout << "3. H-tree" << endl;
	H(1, Center(n), Center(n), Depth(n), 0, 1, 2, 3, v, n);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << " " << H_tree[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}