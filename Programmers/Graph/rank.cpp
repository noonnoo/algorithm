#include <string>
#include <vector>

using namespace std;

int win_lose[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(int i = 0; i < results.size(); i++){
        win_lose[results[i][0]][results[i][1]] = 1;
        win_lose[results[i][1]][results[i][0]] = -1;
    }
    
    for(int k = 1; k <= n ; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n ; j++){
                if(win_lose[i][j] == 0 && win_lose[i][k] != 0 
                   && win_lose[i][k] == win_lose[k][j])
                    win_lose[i][j] = win_lose[i][k];
            }
        }
    }
    
    for(int i = 1; i <= n; i++){   
        bool know = true;
        for(int j = 1; j <= n ; j++){
            if(j != i && win_lose[i][j] == 0){
                know = false;
                break;
            }
        }
        if(know)
            answer++;
    }
    
    return answer;
}
