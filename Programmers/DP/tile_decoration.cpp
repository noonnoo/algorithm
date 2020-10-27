#include <string>
#include <vector>
#include <iostream>

using namespace std;

//피보나치
long long solution(int N) {
    long long answer = 0;
    long long length[81] = { 1, 1, 2, };        //사각형의 길이, 초기에 3개는 미리 입력해둠

    for (int i = 3; i <= 80; i++) 
        length[i] = length[i - 1] + length[i - 2];

    answer = (length[N] + length[N - 1]) * 2;
    return answer;
}

int main() {
    long long answer = solution(6);
    cout << answer << endl;
}
