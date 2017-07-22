#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

#define MAX 1000007

int main()
{
	//freopen("INPUT.INP","rt",stdin);
	int n, m, temp;
	vector <int> a;
	vector <int> b;
	cin >> n >> m;
	for (int i = 0; i<n; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i<m; i++)
	{
		cin >> temp;
		b.push_back(temp);
	}
	int count = 0;
	int j = 0;
	for (int i = 0; i<n; i++)
	{
		for (; j<m; j++)
		{

			if (a[i] == b[j] || b[j]>a[i])
			{
				count++;
				j++;
				break;
			}

		}
	}
	cout << n - count;
	return 0;
}
