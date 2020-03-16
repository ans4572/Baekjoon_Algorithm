/*
�ݿø� �Լ�: round() / �ø� �Լ�: ceil() / ���� �Լ�: floor()
�ֺ��� ã�� ������ �ϱ� ���� ��� ���� ���.
������ ����ؾ� �ϹǷ� count�迭 ���� �� 8001���� ����� -4000~4000
������ �����Ͽ� �����.
*/
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vec;
	vector<int> count(8001); //-4000~4000
	vector<int> result(N);

	for (int i = 0; i < count.size(); ++i)
		count[i] = 0;

	int n;
	int sum = 0;
	int min = 4001, max = -4001;
	for (int i = 0; i < N; ++i)
	{
		cin >> n;
		sum += n;
		if (n > max)
			max = n;
		if (n < min)
			min = n;
		vec.push_back(n);
		count[n + 4000]++;
	}

	//�ֺ� ã��
	int maxFrequency = 0;
	bool second = false; //�ֺ� �� �� ��°�� ���� ���� ã�� ���� ����
	for (int i = 0; i < count.size(); ++i)
	{
		if (count[i] > count[maxFrequency]) {
			if (second == true)
				second = false;
			maxFrequency = i;
		}
		else if (count[i] == count[maxFrequency] && second == false) {
			maxFrequency = i;
			second = true;
		}
	}

	//������
	for (int i = 0; i < count.size() -1 ; ++i)
	{
		count[i + 1] += count[i];
	}

	//�����ϱ�
	for (int i = N-1; i >= 0; --i) {
		result[count[vec[i] + 4000]-1] = vec[i];
		count[vec[i] + 4000]--;
	}

	cout << round((double)sum / N) << "\n";
	cout << result[N/2] << "\n";
	cout << (maxFrequency - 4000) << "\n";
	cout << max - min << "\n";

	return 0;
}