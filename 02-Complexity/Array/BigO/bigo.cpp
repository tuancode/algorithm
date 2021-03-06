#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 111111

int a[maxn], c[maxn];
int cnt;

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	int j = 0;
	//Tìm đoạn dài nhất có chứa k số phân biệt
	for (int i = 1; i <= n; i++)
	{
		c[a[i]]++;
		if (c[a[i]] == 1)
			cnt++;
		//Sau khi tìm thấy đoạn dài nhất thì bắt đầu rút ngắn nó lại rút ngắn cho đến khi nào không thể rút ngắn được nữa thì đó là đoạn cần tìm
		while (cnt == k)
		{
			j++;
			c[a[j]]--;
			if (c[a[j]] == 0)
			{
				cout << j << " " << i;
				return 0;
			}
		}

	}
	//Nếu tronng vòng lặp trên không tìm được đoạn nào thì thoát ra và in giá trị -1 -1
	cout << "-1 -1";

	return 0;
}