#include<iostream>
#include<vector>

using namespace std;

//mergeSort
int temp[500001];
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

	//merge ��Ʈ�� �̿��Ͽ� A�迭�� �����Ѵ�.
	mergeSort(A, 0, A.size() - 1);

	int M;
	cin >> M;

	vector<int> countFind(M); //ã���� �ϴ� ���� ������ ������ �迭
	int left, right, mid;
	//�̺� Ž���� �̿��Ͽ� �� �Է°����� A�迭�� �����ϴ��� ���� �Ǻ� �� ���� ���ϱ�
	for (int i = 0; i < M; ++i)
	{
		cin >> n;
		left = 0, right = N - 1, mid = (left + right) / 2;
		countFind[i] = 0;
		//left�� ���� right���� Ŀ�������� �ݺ�
		while (left <= right)
		{
			//�߰����� ã�����ϴ� ������ ũ�ٸ� ��������
			if (A[mid] > n)
				right = mid - 1;
			//�߰����� ã�����ϴ� ������ �۴ٸ� ����������
			else if (A[mid] < n)
				left = mid + 1;
			//�߰����� ã�����ϴ� ���� ���ٸ� �߰��Ѱ��̹Ƿ� �� ���� ���鼭 ������ ã���ֱ�
			else if (A[mid] == n)
			{
				int lowerBound, upperBound;
				//���� �κп��� lowerBoundã��
				int newLeft = 0, newRight = mid - 1 , newMid = (newLeft+newRight)/2;
				while (newLeft < newRight)
				{
					if (A[newMid] < n)
						newLeft = newMid + 1;
					else if (A[newMid] == n)
						newRight = newMid - 1;
					newMid = (newLeft + newRight) / 2;
				}
				lowerBound = newLeft;
				
				//������ �κп��� upperBoundã��
				newLeft = mid+1, newRight = right, newMid = (newLeft + newRight) / 2;
				while (newLeft < newRight)
				{
					if (A[newMid] > n)
						newRight = newMid - 1;
					else if (A[newMid] == n)
						newLeft = newMid + 1;
					newMid = (newLeft + newRight) / 2;
				}
				upperBound = newRight;

				if(A[lowerBound] != n && A[upperBound] != n)
					countFind[i] = upperBound - lowerBound - 1;
				else if (A[lowerBound] == n && A[upperBound] == n) 
					countFind[i] = upperBound - lowerBound + 1;
				else
					countFind[i] = upperBound - lowerBound;
				break;
			}
			//�Ź� �ݺ��� �� ������ mid���� ���Ӱ� ����
			mid = (left + right) / 2;
		}
	}

	//���
	for (int i = 0; i < M; ++i)
		cout << countFind[i] << "\n";

	return 0;
}