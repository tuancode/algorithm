#include <iostream>
#include <stack>

using namespace std;

int main() {
	int numberOfCar, car;
	stack<int> lane;
	int nextCar = 1;
	
	cin >> numberOfCar;
	
	while (1) {
		if (numberOfCar == 0) {
			return 0;
		}
		
		for (int i = 0; i < numberOfCar; i++) {
			cin >> car;
			if (lane.empty()) {
				if(car == nextCar) {
					nextCar++;
				} else {
					lane.push(car);
				}
			} else {
				while (lane.top() == nextCar) {
					nextCar++;
					lane.pop();
				}
				if (car > lane.top()) {
					cout << "no";
					return 0;
				} else {
					lane.push(car);
				}
			}
		}
			
		cout << "yes";
		return 0;
	}
}