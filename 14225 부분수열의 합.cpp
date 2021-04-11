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
vector<int> S;
vector<int> partSum;

void makePartSum(int index, int sum) {
    if (index >= N) {
        partSum.push_back(sum);
    }
    else {
        makePartSum(index + 1, sum + S[index]);  //�ش� �ε����� ���� �� ���ؼ� �ѱ��
        makePartSum(index + 1, sum);             //�ش� �ε����� ���� �� ��ŵ�ؼ� �ѱ��
    }

    return;
}

int main() {
    cin >> N;

    S.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    sort(S.begin(), S.end());

    makePartSum(0, 0);

    sort(partSum.begin(), partSum.end());
   
    int ans = 1;
    int index = 0;
    while (index < partSum.size()) {
        if (ans == partSum[index])
            ans++;
        else if (ans < partSum[index])
            break;
        
        index++;
    }

    cout << ans << endl;

    return 0;
}