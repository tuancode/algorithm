// Vẫn dùng biến j để chạy nhưng j không phải lúc nào cũng reset về bằng 0
// mà nó luôn chạy theo i để cập nhật đoạn dài nhất
#include <iostream>
#include <cstdio>

using namespace std;

#define MAX 100007

int main()
{
    //freopen("INPUT.INP", "rt", stdin);
    int n, t, a[MAX], max = 0, j = 0, count = 0;
    cin >> n >> t;
    for (int i = 0; i<n; i++)
    {
        cin >> a[i];
        while (t<a[i])
        {
            t += a[j];
            j++;
            count--;
        }
        t -= a[i];
        count++;
        if (count>max)
            max = count;
    }
    cout << max;
    return 0;
}