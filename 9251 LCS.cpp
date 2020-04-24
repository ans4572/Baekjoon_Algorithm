#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int dy[1001][1001];  //dy[i][j]: �� ���ڿ��� ���̰� ���� i�� ���� j�϶��� ���� ���� ����.

int main() {
	string a, b;
	cin >> a;
	cin >> b;

	int ans = 0;
	//a�� �������� b�� �ϳ��� �߰��ϸ鼭 ���� �� ���̸� ã�´�.
	for (int i = 1; i <= b.length(); ++i) {
		for (int j = 1; j <= a.length(); ++j) {
			//a�� ���ڿ� b�� ���ڰ� ���� ���, ���� �밢������ +1�� �����ش�.
			if (a[j - 1] == b[i - 1]) {
				dy[i][j] = dy[i - 1][j - 1] + 1;
			}
			//a�� ���ڿ� b�� ���ڰ� �ٸ� ���, ���ʰ� ���� �� ū ���� �����Ѵ�.
			else {
				dy[i][j] = max(dy[i - 1][j], dy[i][j - 1]);
			}
			if (ans < dy[i][j])
				ans = dy[i][j];
		}
	}
	
	cout << ans << endl;

	return 0;
}