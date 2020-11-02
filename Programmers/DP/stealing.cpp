#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> money) {
    int answer = 0, n = money.size();
    vector<long> dp(money.size(), 0), dp2(money.size(), 0);
    dp[1] = money[1];       //dp는 첫번째를 선택하지 않는 경우
    dp2[0] = money[0];      //dp2는 첫번째를 선택하는 경우
    dp2[1] = money[1] > money[0] ? money[1] : money[0];

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] > money[i] + dp[i - 2] ? dp[i - 1] : dp[i - 2] + money[i];
        dp2[i] = dp2[i - 1] > money[i] + dp2[i - 2] ? dp2[i - 1] : dp2[i - 2] + money[i];
    }
    answer = dp[n - 1] >= dp2[n - 2] ? dp[n - 1] : dp2[n - 2];

    return answer;
}
