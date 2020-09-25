#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int index = 0, mininum = 2147483647;
int cctvs[8][4];        //cctv 타입, 방향, r, c 위치;
int watch[5][4][4] = { {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}},    //cctv1 북,동,남,서
                       {{1,0,1,0}, {0,1,0,1}, {1,0,1,0}, {0,1,0,1}},    //cctv2
                       {{1,1,0,0}, {0,1,1,0}, {0,0,1,1}, {1,0,0,1}},    //cctv3
                       {{1,1,0,1}, {1,1,1,0}, {0,1,1,1}, {1,0,1,1}},    //cctv4
                       {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}} };  //cctv5

void get_blindspot(vector<vector<int>> map) {
    int ret = 0;
    for (int i = 0; i < index; i++) {
        int r = cctvs[i][2];
        int c = cctvs[i][3];
        for (int n = r - 1; watch[cctvs[i][0]][cctvs[i][1]][0] && n >= 0; n--) {    //해당 방향을 확인해야하고, map안에 있을 때 진행
            if (map[n][c] == 6)
                break;
            if (map[n][c] == 0)
                map[n][c] = 7;      //가시 영역
        }
        for (int e = c + 1; watch[cctvs[i][0]][cctvs[i][1]][1] && e < M; e++) {     //동
            if (map[r][e] == 6)
                break;
            if (map[r][e] == 0)
                map[r][e] = 7;
        }
        for (int s = r + 1; watch[cctvs[i][0]][cctvs[i][1]][2] && s < N; s++) {     //남
            if (map[s][c] == 6)
                break;
            if(map[s][c] == 0)
                map[s][c] = 7;
        }
        for (int w = c - 1; watch[cctvs[i][0]][cctvs[i][1]][3] && w >= 0; w--) {    //서
            if (map[r][w] == 6)
                break;
            if (map[r][w] == 0)
                map[r][w] = 7;
        }
    }

    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            if (map[i][j] == 0)
                ret++;

    if (mininum > ret)
        mininum = ret;
}

void dfs(vector<vector<int>> &map, int curr) {      //dfs로 회전된 cctv 모든 경우 구현
    if (index == curr) {
        get_blindspot(map);
        return;
    }

    for (int i = 0; i < 4; i++) {
        cctvs[curr][1] = i;
        dfs(map, curr + 1);
    }
}

int main() {
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {   
            cin >> map[i][j];
            if (map[i][j] > 0 && map[i][j] < 6) {       //cctv인경우 정보 저장
                cctvs[index][0] = map[i][j] - 1;        //cctv 타입
                cctvs[index][1] = 0;                    //cctv 방향
                cctvs[index][2] = i;                    //cctv r위치
                cctvs[index++][3] = j;                  //cctv c위치
            }
        }
    }
    dfs(map, 0);

    cout << mininum;                                    //minimum 구하기
}
