#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> div;
	int n;
	for (int i = 0; i < 10; ++i)
	{
		cin >> n;
		n %= 42;
		bool same = false;
		for (int j = 0; j < div.size(); ++j)
		{
			if (div[j] == n)
				same = true;
		}
		if (!same)
			div.push_back(n);
	}
	cout << div.size() << endl;

	return 0;
}