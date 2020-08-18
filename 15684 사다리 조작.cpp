#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M, H;
bool change[31][11];  //change[a][b]: a��° �����ٰ� b��° �����ٿ��� ��ȭ �߻�
int ans = 4;          //���� �ִ밪�� 3�̹Ƿ� 4�� �ʱ�ȭ

//N���� i��° ���μ��� ����� ���� i���� �������� Ȯ��
bool check() {
	for (int i = 1; i <= N; ++i) {
		int n = i, h = 1;
		while (h <= H) {
			if (change[h][n]) n++;
			else if (n > 1 && change[h][n - 1]) n--;

			h++;
		}

		//�ϳ��� �ٸ� ��� false��ȯ
		if (n != i) return false;
	}
	return true;
}

void DFS(int count, int n, int h) {
	if (count > 3) return;  //3�� �Ѵ� ��� ���̻� �ǹ� x

	//�������� ������ ���
	if (n == N) {
		if (check() && ans > count)
			ans = count;

		return;
	}
	else {
		int nextN = n, nextH = h + 1;
		if (h == H) {
			nextN = n + 1;
			nextH = 1;
		}

		if (!change[h][n]) {
			change[h][n] = true;
			DFS(count + 1, nextN, nextH);
			change[h][n] = false;
		}
		DFS(count, nextN, nextH);
	}
}

int main() {
	cin >> N >> M >> H;

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		change[a][b] = true;
	}

	DFS(0, 1, 1);

	if (ans == 4) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}