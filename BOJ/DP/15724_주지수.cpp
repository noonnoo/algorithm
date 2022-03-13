#include <iostream>
using namespace std;

int population[1025][1025] = { 0, };
int accumulated[1025][1025] = { 0, };

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> population[i][j];
            accumulated[i][j] = accumulated[i][j-1] + accumulated[i-1][j] - accumulated[i-1][j-1] + population[i][j];
        }
    }

    int K;
    int x1, y1, x2, y2;
    cin >> K;
    while(K--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << accumulated[x2][y2] - (accumulated[x1-1][y2] + accumulated[x2][y1-1] - accumulated[x1-1][y1-1]) << "\n";
    }
}