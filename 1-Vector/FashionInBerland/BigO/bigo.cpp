#include <bits\stdc++.h>
using namespace std;

int main()
{
	//freopen("INPUT.INP", "rt", stdin);
	int n;
	int temp;
	int count = 0;
	int res = 1;
	scanf("%d", &n);
	//Xét trường hợp có 1 chiếc nút.
	if(n==1)
	{
		scanf("%d", &temp);
		if(temp==1)
		{
			printf("YES");
			return 0;
		}
		else
		{
			printf("NO");
			return 0;
		}
	}
	//Nếu từ 2 chiếc  trở lên thì đếm xem số lượng chiếc nút không được cài lớn hơn 1 là NO ngược lại là YES
	for(int i=0; i<n; i++)
	{
		scanf("%d", &temp);
		if(temp==0)
			count++;
		if(count>1)
		{
			res = 0;
			break;
		}
	}
	if(res==1 && count==1)
		printf("YES");
	else
		printf("NO");
	return 0;
}