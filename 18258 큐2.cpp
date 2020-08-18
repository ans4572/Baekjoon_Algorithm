#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int queue[2000000];
int front = -1, back = -1;

void push(int x) {
	queue[++front] = x;
}

void pop() {
	if (front == back)
		cout << -1 << endl;
	else
		cout << queue[back++] << endl;
}

void size() {
	cout << front - back << endl;
}

bool empty() {
	if (front == back)
		return true;
	else
		return false;
}

void Front() {
	if (empty())
		cout << -1 << endl;
	else
		cout << queue[front] << endl;
}

void Back() {
	if (empty())
		cout << -1 << endl;
	else
		cout << queue[front] << endl;
}

int main() {


	return 0;
}