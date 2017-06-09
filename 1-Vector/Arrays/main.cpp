#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nA, nB;
    int k, m;
    int input;
    vector<int> A, B;

    cin >> nA >> nB;
    cin >> k >> m;

    for (int i = 0; i < nA; ++i) {
        cin >> input;
        A.push_back(input);
    }

    for (int i = 0; i < nB; ++i) {
        cin >> input;
        B.push_back(input);
    }

	for (int i = 0; i < nB; i++) {
		if (A.back() < B[i]) {
			if (B[i] == B.back()) {
				cout << "YES";
				return 0;
			}
		}
    }

    cout << "NO";
    return 0;
}
