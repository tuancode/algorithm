#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//freopen("INPUT.INP", "rt", stdin);
	int n, temp, flag;
	vector<int> v;
	int count = 0;
	cin >> n;
	//Bỏ tất cả giá trị vào vector
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	//Chạy và xét từng giá trị
	for (int i = 0; i<n; i++)
	{
		flag = 0;
		temp = v[i];
		for (int j = 1; j <= 15; j++)
		{
			//Tăng từng phút lên để kiểm tra 
			count++;
			if (count == temp)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			break;
		}
		//Xét trường hợp đặc biệt nếu như số cuối cùng vẫn còn xét được thì phải cộng thêm thời gian xem là 15 phút
		//Nếu cộng thêm mà lớn hơn thì gán bằng 90 (do số phút không lớn hơn 90).
		if (i == n - 1 && flag == 1)
		{
			count = count + 15;
			if (count > 90)
				count = 90;
		}
	}
	cout << count;
	return 0;
}