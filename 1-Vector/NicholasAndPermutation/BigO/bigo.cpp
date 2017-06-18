#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//freopen("INPUT.INP", "rt", stdin);
	int n, max, pos1, posn, temp;
	vector<int> a;
	cin >> n;
	//Tìm vị trí chứa số nhỏ nhất và lớn nhất
	for (int i = 0; i<n; i++)
	{
		cin >> temp;
		a.push_back(temp);
		if (a[i] == 1)
			pos1 = i;
		if (a[i] == n)
			posn = i;
	}
	//Ta lần lượt xét 4 trường hợp, dời 1 về đầu và cuối, dời n về đầu và cuối. Nếu trường nào nào lớn hơn giá trị
	//max hiện tại thì ta sẽ cập nhật. 
	max = abs(posn - pos1);
	n = n - 1;//Trừ đi 1 bởi vì ta đang tính vị trí.
	if (max < abs(posn - 0))
		max = abs(posn - 0);
	if (max < abs(posn - n))
		max = abs(posn - n);
	if (max < abs(pos1 - 0))
		max = abs(pos1 - 0);
	if (max < abs(pos1 - n))
		max = abs(pos1 - n);
	cout << max;
	return 0;
}