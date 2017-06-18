#include <iostream>
#include <vector>
#define nMax 100000
#define pMax 1000000000

using namespace std;

struct segment{
	int left;
	int right;
};

int main() {
    int n;
    int i, min = pMax, max = 1;
    vector<segment> segments(nMax);
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
		cin >> segments[i].left >> segments[i].right;

		if (segments[i].left < min) {
			min = segments[i].left;
		}
		if (segments[i].right > max) {
			max = segments[i].right;
		}
	}
	
	for(i = 0; i < n; i++) {
		if (segments[i].left == min && segments[i].right == max) {
			cout << i+1;
			return 0;
		}
	}
	
	cout << "-1";
	return 0;
}
