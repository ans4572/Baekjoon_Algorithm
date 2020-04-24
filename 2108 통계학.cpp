/*
�ݿø� �Լ�: round() / �ø� �Լ�: ceil() / ���� �Լ�: floor()
�ֺ��� ã�� ������ �ϱ� ���� ��� ���� ���.
������ ����ؾ� �ϹǷ� count�迭 ���� �� 8001���� ����� -4000~4000
������ �����Ͽ� �����.
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vec;
	vector<int> count(8001,0);   //-4000~4000 �� ���� ī��Ʈ ����

	int num;
	int sum = 0;                 //��� ��� ���ϱ� ���� N���� ������ ��
	int min = 4001, max = -4001; //������ ���ϱ� ���� �ּڰ��� �ִ�
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		sum += num;         
		if (num > max)
			max = num;
		if (num < min)
			min = num;
		vec.push_back(num);
		count[num + 4000]++;   //count[0] => -4000 , count[8000] => 4000 �̴�.
	}

	//�ֺ� ã��
	int maxFrequency = 0;
	bool second = false;   //������ �ִ� �ֺ� �� �� ��°�� ���� ���� ã�� ���� boolŸ��
	int secondFrequency;
	for (int i = 1; i <= 8000; ++i)
	{
		if (count[i] > count[maxFrequency]) {
			//�� ū ���� ã�Ҵٸ� second�� �̹� ������ ��츦 ���� �ٽ� false�� �ٲ��ش�.
			second = false;
			maxFrequency = i;
		}
		//���� ū ���� �����鼭 �� ��°�� ���� ���� ã�� ���
		else if (count[i] == count[maxFrequency] && second == false) {
			second = true;
			secondFrequency = i;
		}
	}

	sort(vec.begin(), vec.end());

	cout << round((double)sum / N) << endl;
	cout << vec[N / 2] << endl;
	if (second == false)
		cout << (maxFrequency - 4000) << endl;
	else
		cout << (secondFrequency - 4000) << endl;
	cout << abs(max - min) << endl;

	return 0;
}