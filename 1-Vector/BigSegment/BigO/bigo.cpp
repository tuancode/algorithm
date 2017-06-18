#include <iostream>
#include <cstdio>
#define M 100005
#define oo 1000000007
using namespace std;

int N, res = -1, l[M], r[M];

int main()
{
	//freopen("INPUT.INP", "rt", stdin);
	cin >> N;
	int left = oo, right = 0;

	for (int i = 0; i<N; i++)
	{
		cin >> l[i] >> r[i];
		if (left > l[i])
			left = l[i];
		if (right < r[i])
			right = r[i];
	}
	for (int i = 0; i<N; i++)
		if (left == l[i] && right == r[i])
		{
			res = i + 1;
			break;
		}
	cout << res << endl;
	return 0;
}