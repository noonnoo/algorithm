#include <iostream>
#include <cstring>
using namespace std;

int DP[10001];
int coin[21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    int N, M;

    cin >> T;
    while(T--){
        memset(DP, 0, sizeof(DP));
    
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> coin[i];
        cin >> M;

        DP[0] = 1;
        for(int i = 0; i < N; i++){
            for(int j = coin[i]; j <= M; j++){
                DP[j] = DP[j] + DP[j - coin[i]];
            }
        }
        cout << DP[M] << "\n";
    }
}