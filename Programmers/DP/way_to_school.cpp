#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    int** count = new int* [m];                     //count 2차원 배열 생성
    for (int i = 0; i < m; i++) {
        count[i] = new int[n];
        fill(count[i], count[i]+n, 1);
    }

    for (int i = 0; i < puddles.size(); i++)        //물에 잠긴 곳은 0
        count[puddles[i][0] - 1][puddles[i][1] - 1] = 0;

    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) {
            if ((i == 0 && j == 0) || count[i][j] == 0) continue;
            if (i == 0)                             //맨 윗줄은 왼쪽만 신경쓸 것
                count[i][j] = count[i][j - 1];
            else if (j == 0)                        //맨 왼쪽줄은 위쪽만 신경쓸 것
                count[i][j] = count[i - 1][j];
            else {                                   
                count[i][j] =  count[i - 1][j] + count[i][j - 1];
            }
            count[i][j] %= 1000000007;              //빼먹었던 나머지 연산
        }

    answer = count[m - 1][n - 1];

    for (int i = 0; i < m; i++)
        delete[] count[i];
    delete[] count;

    return answer;
}

int main() {
    vector<vector<int>> puddles = { {2,2} };
    cout << solution(4, 3, puddles) << endl;
}
