#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

class Camera {
public:
	int n, m, num;
	bool dic[4] = { false, false, false, false };  //��, ������, �Ʒ�, ����

	Camera() {}
	Camera(int n, int m, int num) {
		this->n = n;
		this->m = m;
		this->num = num;
	}
};

int N, M;
int map[8][8];
vector<Camera> camera;
int ans = 64;

//ī�޶� ���� ���� �߿� true�� �͵��� üũ
void doCamare(Camera c) {
	//��
	if (c.dic[0]) {
		for (int i = c.n - 1; i >= 0; --i) {
			if (map[i][c.m] == 6) break;
			if (map[i][c.m] == 0) map[i][c.m] = 7;
		}
	}
	//������
	if (c.dic[1]) {
		for (int i = c.m + 1; i < M; ++i) {
			if (map[c.n][i] == 6) break;
			if (map[c.n][i] == 0) map[c.n][i] = 7;
		}
	}

	//�Ʒ�
	if (c.dic[2]) {
		for (int i = c.n + 1; i < N; ++i) {
			if (map[i][c.m] == 6) break;
			if (map[i][c.m] == 0) map[i][c.m] = 7;
		}
	}
	//����
	if (c.dic[3]) {
		for (int i = c.m - 1; i >= 0; --i) {
			if (map[c.n][i] == 6) break;
			if (map[c.n][i] == 0) map[c.n][i] = 7;
		}
	}
}

void findMin(int index) {
	if (index == camera.size()) {
		//�� ī�޶󸶴� ������ ���� ����
		for (int i = 0; i < camera.size(); ++i) {
			doCamare(camera[i]);
		}

		int count = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (map[i][j] == 0) count++;
				if (map[i][j] == 7)	map[i][j] = 0;    //�ٽ� ��ĭ���� ó��
			}
		}

		if (ans > count) ans = count;
	}
	else {
		if (camera[index].num == 1) {
			for (int i = 0; i < 4; ++i) {
				camera[index].dic[i] = true;
				findMin(index + 1);
				camera[index].dic[i] = false;
			}
		}
		else if (camera[index].num == 2) {
			for (int i = 0; i < 2; ++i) {
				camera[index].dic[i] = true;
				camera[index].dic[i + 2] = true;
				findMin(index + 1);
				camera[index].dic[i] = false;
				camera[index].dic[i + 2] = false;
			}
		}
		else if (camera[index].num == 3) {
			for (int i = 0; i < 4; ++i) {
				camera[index].dic[i] = true;
				camera[index].dic[(i + 1) % 4] = true;
				findMin(index + 1);
				camera[index].dic[i] = false;
				camera[index].dic[(i + 1) % 4] = false;
			}
		}
		else if (camera[index].num == 4) {
			for (int i = 0; i < 4; ++i) {
				camera[index].dic[i] = true;
			}

			for (int i = 0; i < 4; ++i) {
				camera[index].dic[i] = false;
				findMin(index + 1);
				camera[index].dic[i] = true;
			}
		}
		else {
			for (int i = 0; i < 4; ++i)
				camera[index].dic[i] = true;

			findMin(index + 1);
		}
	}

	return;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				camera.push_back(Camera(i, j, map[i][j]));
			}
		}
	}

	findMin(0);

	cout << ans << endl;

	return 0;
}