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
        //양 끝이 같다면
        if (S[i] == S[S.length() - 1])
        {
            //하나씩 땡기면서 양 끝을 확인

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