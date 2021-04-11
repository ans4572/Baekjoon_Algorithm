#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

int main() {
	string S;
	cin >> S;

    int result = 0;

    for (int i = 0; i < S.length() - 1; i++)
    {
        //�� ���� ���ٸ�
        if (S[i] == S[S.length() - 1])
        {
            //�ϳ��� ����鼭 �� ���� Ȯ��

            int start = i;
            int end = S.length() - 1;

            for (int j = 0; j < (S.length() - i) / 2; j++)
            {
                if (S[start] == S[end])
                {
                    start++;
                    end--;
                }
                else
                {
                    result++;
                    break;
                }
            }
            if (start >= end)
                break;
        }
        else
            result++;

    }

    cout << result + S.length() << endl;

	return 0;
}