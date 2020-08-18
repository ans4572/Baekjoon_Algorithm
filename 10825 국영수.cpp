#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class student {
public:
	string name;
	int korean;
	int math;
	int english;

	student(){}

	student(string name, int korean, int math, int english) {
		this->name = name;
		this->korean = korean;
		this->math = math;
		this->english = english;
	}

	bool operator < (student &b) {
		if (this->korean == b.korean) {
			if (this->math == b.math) {
				if (this->english == b.english) {
					return this->name < b.name;
				}
				return this->english > b.english;
			}
			return this->math < b.math;		
		}
		return this->korean > b.korean;
	}
};

void swap(student &a, student &b) {
	student temp = a;
	a = b;
	b = temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<student> s;

	string name;
	int k, m, e;

	for (int i = 0; i < N; ++i) {
		cin >> name >> k >> m >> e;
		s.push_back(student(name, k, m, e));
	}

	sort(s.begin(), s.end());

	for (int i = 0; i < N; ++i) {
		cout << s[i].name << "\n";
	}

	return 0;
}