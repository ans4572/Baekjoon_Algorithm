#include<iostream>
#include<string>

using namespace std;

int main()
{
	string word;
	int sum = 0;
	cin >> word;
	for (int i = 0; i < word.length(); i++)
	{
		if ((word[i] == 'c' || word[i] == 's' || word[i] == 'z') && word[i + 1] == '=')
		{
			sum += 1;
			i += 1;
		}
		else if ((word[i] == 'c' || word[i] == 'd') && word[i + 1] == '-')
		{
			sum += 1;
			i += 1;
		}
		else if ((word[i] == 'l' || word[i] == 'n') && word[i + 1] == 'j')
		{
			sum += 1;
			i += 1;
		}
		else if (word[i] == 'd' && word[i + 1] == 'z' && word[i + 2] == '=')
		{
			sum += 1;
			i += 2;
		}
		else
			sum += 1;
	}
	cout << sum;

	return 0;
}
