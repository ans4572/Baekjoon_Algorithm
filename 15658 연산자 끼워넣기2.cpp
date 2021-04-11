#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

int N;
vector<int> num;
int op[4];  // + , - , * , /
int minAns = 1000000000, maxAns = -1000000000;

void cal(int index, int result) {
    if (index == N) {
        if (maxAns < result)
            maxAns = result;
        if (minAns > result)
            minAns = result;
    }
    else {
        if (op[0] > 0) {
            op[0]--;
            cal(index + 1, result + num[index]);
            op[0]++;
        }
        if (op[1] > 0) {
            op[1]--;
            cal(index + 1, result - num[index]);
            op[1]++;
        }
        if (op[2] > 0) {
            op[2]--;
            cal(index + 1, result * num[index]);
            op[2]++;
        }
        if (op[3] > 0) {
            op[3]--;
            cal(index + 1, result / num[index]);
            op[3]++;
        }
    }

    return;
}

int main() {
    cin >> N;

    num.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> op[i];
    }

    cal(1, num[0]);

    cout << maxAns << endl;
    cout << minAns << endl;

    return 0;
}