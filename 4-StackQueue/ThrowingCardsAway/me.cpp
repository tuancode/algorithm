#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, char *argv[]) {
	int n, remain, temp;
	stack<int> desk;
	stack<int> discard;
	
	cin >> n;
	
	if (n != 0) {
		for(int i = 1; i <= n; i++) {
			desk.push(i);
		}
		
		for(int i = 0; i < desk.size(); i++) {
			if (desk.size() == 1) {
				discard.push(desk.top());
				desk.pop();
				break;
			}
			
			discard.push(desk.top());
			desk.pop();
			desk.pop();
			
			temp = desk.top();
			desk.push(temp);
		}
		
		for(int i = 0; discard.size(); i++) {
			cout << discard.top() << " ";
			discard.pop();
		}
		
		cout << "\n";
		cout << remain;
		return 0;
	}
}