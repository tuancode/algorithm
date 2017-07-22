#include <iostream>
#include <string>

using namespace std;

int main() {
	string name; // name of exhibit
	char pointer = 'a'; // pointer of embosser
	int middle = 13; // middle pointer position
	int total = 26; // total character of embosser
	int rotation = 0, distance;
	
	cin >> name;
	
	for (int i = 0; i < name.size(); i++) {
		// caculate distance of rotations
		distance = abs(pointer - name[i]);
		if (distance < middle) {
			// use clockwise rotations
			rotation += distance;
		} else {
			// use counterclockwise rotations
			rotation += total - distance;
		}
		// update current postion to pointer
		pointer = name[i];
	}
	
	cout << rotation << endl;
	return 0;
}