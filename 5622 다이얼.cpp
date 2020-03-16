#include<iostream>
#include<string>

using namespace std;

int main()
{
	string word;
	int time = 0;
	cin >> word;

	for (int i = 0; i < word.length(); i++)
	{
		char t = word[i];
		if (t == 'A' || t == 'B' || t == 'C')
			time += 3;
		else if (t == 'D' || t == 'E' || t == 'F')
			time += 4;
		else if (t == 'G' || t == 'H' || t == 'I')
			time += 5;
		else if (t == 'J' || t == 'K' || t == 'L')
			time += 6;
		else if (t == 'M' || t == 'N' || t == 'O')
			time += 7;
		else if (t == 'P' || t == 'Q' || t == 'R' || t == 'S')
			time += 8;
		else if (t == 'T' || t == 'U' || t == 'V')
			time += 9;
		else
			time += 10;
	}
	cout << time;

	return 0;
}