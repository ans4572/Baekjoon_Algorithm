/*
���� ��ü�� �޸� ��뷮�� �����Ƿ� �Ϲ����� ������ķ� Ǯ ���� ����.
c++���� ����� �ð��� ���̱� ���� 
cin.tie(NULL);
ios_base::sync_with_stdio(false);
�� ������ ����ϰ� endl��� \n���.
*/
#include<iostream>

#include<vector>

using namespace std;

//void countingSort(vector<int> &arr,const int &max)
//{
//	vector<int> count(max + 1); //1���� �����̹Ƿ� +1
//	vector<int> result(arr.size());
//
//	//0���� �ʱ�ȭ
//	for (int i = 0; i < count.size(); ++i)
//		count[i] = 0;
//	
//	//�� ������ ������ŭ ����
//	for (int i = 0; i < arr.size(); ++i)
//		count[arr[i]]++;
//
//	//������ ����
//	for (int i = 1; i < count.size()-1; ++i)
//	{
//		count[i + 1] += count[i];
//	}
//	
//	//��� �迭�� ���� �� �ش� ������ - 1
//	for (int k = arr.size() - 1; k >= 0; --k)
//	{
//		result[count[arr[k]]-1] = arr[k];
//		count[arr[k]]--;
//	}
//
//	//����
//	for (int i = 0; i < arr.size(); ++i)
//		arr[i] = result[i];
//}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int n;
	vector<int> count(10001);

	//���� 0���� �ʱ�ȭ
	for (int i = 0; i < 10001; ++i)
		count[i] = 0;

	//�Է¹ް� �� ���� ���� ����
	for (int i = 0; i < N; ++i)
	{
		cin >> n;
		count[n]++;
	}
	
	for (int j = 1; j < count.size(); ++j)
	{
		int n = count[j];
		if (n > 0) {
			while (n > 0) {
				cout << j << "\n";
				n--;
			}
		}
	}

	return 0;
}