#include<iostream>
#include<vector>

using namespace std;

//mergeSort
int temp[100001];
void merge(vector<int> &arr, int l, int m, int r)
{
	int first = l; int second = m + 1;
	int k = 0;
	while (first <= m && second <= r)
	{
		if (arr[first] < arr[second])
			temp[k] = arr[first++];
		else
			temp[k] = arr[second++];
		k++;
	}
	while (first <= m)
		temp[k++] = arr[first++];
	while (second <= r)
		temp[k++] = arr[second++];
	k--;
	while (k >= 0)
	{
		arr[l + k] = temp[k];
		k--;
	}
}

void mergeSort(vector<int> &arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> A;

	int n;
	for (int i = 0; i < N; ++i)
	{
		cin >> n;
		A.push_back(n);
	}

	//merge 소트를 이용하여 A배열을 정렬한다.
	mergeSort(A, 0, A.size() - 1);

	int M;
	cin >> M;

	vector<bool> checkFind(M); //있으면 true, 없으면 false로 판별하기 위한 배열
	int left, right, mid;
	//이분 탐색을 이용하여 각 입력값마다 A배열에 존재하는지 여부 판별
	for (int i = 0; i < M; ++i)
	{
		cin >> n;
		left = 0, right = N - 1, mid = (left + right) / 2;
		checkFind[i] = false;
		//left의 값이 right보다 커질때까지 반복
		while (left <= right)
		{
			//중간값이 찾고자하는 값보다 크다면 왼쪽으로
			if (A[mid] > n)
				right = mid - 1;
			//중간값이 찾고자하는 값보다 작다면 오른쪽으로
			else if (A[mid] < n)
				left = mid + 1;
			//중간값이 찾고자하는 값과 같다면 발견한것이므로 true로 바꿔준 후 반복문 탈출
			else if(A[mid] == n)
			{
				checkFind[i] = true;
				break;
			}
			//매번 반복문 돌 때마다 mid값을 새롭게 설정
			mid = (left + right) / 2;
		}
	}

	//출력
	for (int i = 0; i < M; ++i)
	{
		if (checkFind[i] == true)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}