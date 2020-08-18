#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int arr[10001];
int make[10001];

int main() {
	bool finish = true;  //�������� ���� ���� �Ǵ�
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		if (arr[i] != (N - i + 1)) //�ϳ��� ������ �ƴ� ���  
			finish = false;
	}

	if (finish) {
		cout << -1 << endl;
		return 0;
	}

	//next_permutation ����
	//1. A[i-1] < A[i]�� �����ϴ� ���� ū i�� ã�´�.
	int index1 = N;
	for (int i = N; i > 1; --i) {
		if (arr[i - 1] < arr[i]) {
			index1 = i;
			break;
		}
	}

	//2. j >= i && A[j] > A[i-1]�� �����ϴ� ���� ū j�� ã�´�.
	int index2 = N;
	for (int j = index2; j >= index1; --j) {
		if (arr[j] > arr[index1 - 1]) {
			index2 = j;
			break;
		}
	}

	//3. A[i-1]�� A[j]�� swap�Ѵ�.
	int temp = arr[index1 - 1];
	arr[index1 - 1] = arr[index2];
	arr[index2] = temp;

	//4. A[i]���� ������ �����´�.
	for (int i = 1; i < index1; ++i) {
		make[i] = arr[i];
	}
	for (int i = index1; i <= N; ++i) {
		make[i] = arr[N + index1 - i];
	}

	for (int i = 1; i <= N; ++i)
		cout << make[i] << " ";
	cout << endl;

	return 0;
}