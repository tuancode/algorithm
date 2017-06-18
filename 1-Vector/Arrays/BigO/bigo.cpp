#include <iostream>
using namespace std;
#define MAX 100001

int main()
{
	//freopen("INPUT.INP","rt",stdin);

	long na, nb, k, m;
	long a[MAX], b[MAX];

	cin >> na >> nb;
	cin >> k >> m;

	for (int i = 0; i<na; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i<nb; i++)
	{
		cin >> b[i];
	}

	if (a[k - 1] < b[nb - m])
		cout << "YES";
	else
		cout << "NO";

	return 0;
}