#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int DP[10001];
int calories[5001], prices[5001];
int n, m;
double tmp;

int main(){
    while(true){
        memset(DP, 0, sizeof(DP));
        cin >> n >> tmp;
        if(n == 0 && tmp < 0.001) break;
        m = (int)(tmp * 100.0 + 0.5);                   //부동 소수값 오류 보정  

        for(int i = 0; i < n; i++){
            cin >> calories[i] >> tmp;
            prices[i] = (int)(tmp * 100.0 + 0.5);
        }
        
        for(int i = 0; i < n; i++){                     //i가 돈
            for(int j = prices[i]; j <= m; j++){        //j가 몇번째 사탕인지
                DP[j] = max(DP[j], DP[j - prices[i]] + calories[i]);
            }
        }
        cout << DP[m] << "\n";
    }
}