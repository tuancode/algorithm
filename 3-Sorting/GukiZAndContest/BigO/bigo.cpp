#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define max 2010

int n, ranks[max];

struct student
{
    int id; // chỉ số thật sự sinh viên trong mảng ban đầu
    int mark; // điểm số trong kỳ thi
};

bool option(student a, student b)
{
    return a.mark  > b.mark;
}

int main()
{
    freopen("INPUT.INP", "rt", stdin);
    int n;
    student temp;
    vector<student> a;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        temp.id = i;
        cin >> temp.mark;
        a.push_back(temp);
    }
    // sắp xếp sinh viên lại theo điểm số giảm dần
    sort(a.begin(), a.end(), option);

    // gán sinh viên đầu tiên lúc nào cũng hạng 1
    ranks[a[0].id] = 1;
    // chạy từ sinh viên thứ 2 trở đi
    // nếu sv đó có điểm giống sv trước thì hạng của sv này sẽ bằng sv trước
    // nếu sinh viên đó không bằng điểm sv trước thì hạng của sv này chính là i+1 (do xét từ sv thứ 2)
    for (int i = 1; i<n; i++)
    {
        if (a[i].mark == a[i - 1].mark)
            ranks[a[i].id] = ranks[a[i - 1].id];
        else
            ranks[a[i].id] = i + 1;
    }

    for (int i = 0; i < n; i++)
        cout << ranks[i] << " ";
    return 0;
}
