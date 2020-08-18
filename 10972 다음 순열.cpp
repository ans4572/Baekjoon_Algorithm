#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int arr[10001];
int make[10001];

int main() {
	bool finish = true;  //마지막에 오는 순열 판단
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		if (arr[i] != (N - i + 1)) //하나라도 역순이 아닌 경우  
			finish = false;
	}

	if (finish) {
		cout << -1 << endl;
		return 0;
	}

	//next_permutation 구현
	//1. A[i-1] < A[i]를 만족하는 가장 큰 i를 찾는다.
	int index1 = N;
	for (int i = N; i > 1; --i) {
		if (arr[i - 1] < arr[i]) {
			index1 = i;
			break;
		}
	}

	//2. j >= i && A[j] > A[i-1]를 만족하는 가장 큰 j를 찾는다.
	int index2 = N;
	for (int j = index2; j >= index1; --j) {
		if (arr[j] > arr[index1 - 1]) {
			index2 = j;
			break;
		}
	}

	//3. A[i-1]과 A[j]를 swap한다.
	int temp = arr[index1 - 1];
	arr[index1 - 1] = arr[index2];
	arr[index2] = temp;

	//4. A[i]부터 순열을 뒤집는다.
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