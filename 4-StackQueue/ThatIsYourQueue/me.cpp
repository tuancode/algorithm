/*
 * main.cpp
 * 
 * Copyright 2017 Tuan Vu <tuancode@icloud.com>
 * 
 * Homework 2 - Stack and Queue
 * https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3359
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

int main() {
	int p, c, x, i;
	queue<int> q, temp;
	vector<int> s;
	string e;
	
	while (1) {
		cin >> p >> c;
		
		if (p == 0 && c == 0) {
			break;
		} else {
			s.push_back(-1);
		};

		for (i = 1; i <= p && i <= c; i++) {
			q.push(i);
		}
		
		for (i = 1; i <= c; i++) {
			cin >> e;
			if (e == "N") {
				s.push_back(q.front());
				q.pop();
				q.push(s.back());
			} else {
				cin >> x;
				temp.push(x);
				while (!q.empty()) {
					if (x != q.front()){
						temp.push(q.front());
					}
					q.pop();
				}
				swap(q, temp);
			}
		}
		
		queue<int> empty;
		swap(q, empty);
	}
	
	int count = 0;
	for (unsigned j = 0; j < s.size(); j++) {
		if (s[j] == -1) {
			count++;
			cout << "Case " << count << ":\n";
		} else {
			cout << s[j] << "\n";
		}
	}
	return 0;
}
