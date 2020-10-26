#include <string>
#include <vector>
#include <iostream>
using namespace std;

//스트라이크, 볼 수를 질문수와 비교해서 들어갈 수 있는 수인지 아닌지 알아보는 함수
//시간복잡도 O(9)
bool isImpossible(vector<int> baseball, int num) {
    string mynum = to_string(num);
    string basenum = to_string(baseball[0]);
    int strike = 0, ball = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j && basenum[i] == mynum[j]) {
                if (baseball[1] < ++strike) return true;
                else break;
            }
            else if (basenum[i] == mynum[j]) {
                if (baseball[2] < ++ball) return true;
                else break;
            }
        }
    }

    if (strike == baseball[1] && ball == baseball[2])
        return false;
    else return true;
}

//123부터 987까지 서로 다른 세수로 이루어진 세자리수를 isImpossible에 넣어서 비교
//시간복잡도 최대 O(100 * 336 * 9)
int solution(vector<vector<int>> baseball) {
    int answer = 0;   
    bool allnum[988] = { false, };

    for (int i = 0; i < baseball.size(); i++) {
        for (int j = 123; j < 988; j++) {
            if (allnum[j]) continue;
            if ((j / 100 != (j / 10 % 10)) && ((j / 10 % 10) != (j % 10)) && (j / 100 != (j % 10))
                && ((j / 10 % 10) != 0) && ((j % 10) != 0)) {
                allnum[j] = isImpossible(baseball[i], j);
            } else {
                allnum[j] = true;
            }

            if (i == baseball.size() - 1 && !allnum[j]) {
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> baseball = { {123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1} };
    cout << solution(baseball) << endl;
}
