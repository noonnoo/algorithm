#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> left, vector<int> right) {
    int answer = 0, n = left.size();

    int** score = new int*[n + 1];
    for (int i = 0; i < n + 1; i++) {
        score[i] = new int[n + 1];
        memset(score[i], 0, sizeof(int) * (n + 1));
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (right[i] < left[j]) {
                score[i][j] = score[i + 1][j] + right[i];
            } else {
                score[i][j] = score[i + 1][j + 1] >= score[i][j + 1] ? score[i + 1][j + 1] : score[i][j + 1];
            }
        }
    }
    answer = score[0][0];

    for (int i = 0; i < n + 1; i++)
        delete[] score[i];
    delete[] score;

    return answer;
}

int main() {
    cout << solution({ 3,2,5 }, { 2,4,1 });
}
