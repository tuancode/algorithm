/*
 * main.cpp
 * 
 * Copyright 2017 Tuan Vu <tuancode@icloud.com>
 * 
 * Homework 1 - Stack and Queue
 * http://www.spoj.com/problems/ONP/ 
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int getPriority(char opr) {
	switch (opr) {
		case '+':
			return 1;
		case '-':
			return 2;
		case '*':
			return 3;
		case '/':
			return 4;
		case '^':
			return 5;
		default:
			return 0;
	}
}

int main() {
	unsigned t, i, j;
	stack<char> opr;
	string infix, postfix;
	vector<string> output;
	
	cin >> t;
	
	for (i = 0; i < t; i++) {
		cin >> infix;
		for (j = 0; j < infix.size(); j++) {
			if (isalpha(infix[j])) {
				postfix += infix[j];
			} else if(infix[j] == '(') {
				opr.push(infix[j]);
			} else if(infix[j] == ')') {
				char temp = opr.top();
				opr.pop();
				while (temp != '(') {
					postfix += temp;
					temp = opr.top();
					opr.pop();
				}
			} else if (getPriority(infix[j]) < getPriority(opr.top())) {
				postfix += opr.top();
				opr.pop();
			} else {
				opr.push(infix[j]);
			}
		}
		
		output.push_back(postfix);
		postfix.clear();
	}
	
	for(i = 0; i < output.size(); i ++) {
		cout << output[i] << "\n";
	}

	return 0;
}
