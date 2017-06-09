#include <iostream>
#include <string>

using namespace std;

int main() {
	string s, t; // s is lexicographically less than t
	
	cin >> s >> t;
	
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] != 'z') {
			s[i]++;
			break;
		} else {
			s[i] = 'a';
		}
	}
	
	if (s < t) {
		cout << s << endl;
	} else {
		cout << "No such string" << endl;
	}
	return 0;
}