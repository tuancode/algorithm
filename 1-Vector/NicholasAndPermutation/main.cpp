#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	vector<int> a;
	int minPos, maxPos, leftDist, rightDist, dist;

	cin >> n;
	a.resize(n);
	dist = n-1;
	
	// Get the maximum and minimum position
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			minPos = i;
		}
		if (a[i] == n) {
			maxPos = i;
		}
	}
	
	leftDist = minPos - 0;
	rightDist = n - maxPos;
	
	if (leftDist > rightDist) {
		dist = minPos - 1;
	} else if (leftDist < rightDist) {
		dist = n - maxPos;
	}
	
	cout << dist;
	return 0;
}
