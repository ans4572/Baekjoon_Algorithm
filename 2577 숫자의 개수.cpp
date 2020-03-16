#include<iostream>
#include<string>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int mul = A * B * C;
	string s = to_string(mul);

	int number[10] = { 0 };
	
	for (int i = 0; i < s.size(); ++i)
		number[s[i]-'0']++;

	for (int i = 0; i < 10; ++i)
		cout << number[i] << endl;

	return 0;
}