#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int H, W, N; //높이 , 넓이, 손님 번호
	int room;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		//손님 번호가 높이보다 낮을 경우와 아닌 경우 나눔
		if (H >= N) {
			room = N * 100 + 1;
		}
		else {
			//방 앞에 숫자를 정할때 N%H를 0이냐 아니냐에 따라 경우를 나눔 
			if (N % H == 0) {
				room = H * 100 + N / H;
			}
			else {
				room = (N % H) * 100 + (N / H) + 1;
			}
		}
		cout << room << endl;
	}
}