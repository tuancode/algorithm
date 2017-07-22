#include <iostream>
#include <vector>
using namespace std;

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n, h, temp;
	vector<int> v;
	cin >> n >> h;

	//Bỏ các giá trị vào vector
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	int s = 0;
	for (int i = 0; i<n; i++)
	{
		temp = v[i];
		//Nếu chiều cao của người nào lớn hơn h thì sẽ +2
		if (temp>h)
			s = s + 2;
		//Nếu nhỏ hơn thì +1
		else
			s = s + 1;
	}
	cout << s;
	return 0;
}