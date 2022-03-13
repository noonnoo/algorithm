#include <iostream>
#include <algorithm>
using namespace std;

int DP[101][10001];
int times[101];
int scores[101];

int main(){
    int N, T, result = -1;
    cin >> N >> T;

    for(int i = 1; i <= N; i++)
        cin >> times[i] >> scores[i];
    
    for(int i = 1 ; i <= N; i++){
        for(int j = 0; j <= T; j++){
            if(j < times[i])
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - times[i]] + scores[i]);
        }
        result = max(DP[i][T], result);
    }
    cout << result;
}