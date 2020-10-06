#include <iostream>
#include <deque>
using namespace std;

int N, M, K, num = 0;			//input
int land[11][11];				//현재 땅의 양분
int A[11][11];					//로봇이 겨울에 뿌리는 땅별 양분
int around[8][2] = { {-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };		//8가지 방향

deque<int> trees[11][11];		//나무
int dead[11][11];				//해당 년도에 죽은 나무

void ss() {						//spring summer
	for (int i = 1; i <= N; i++) {		//spring: N*N의 i,j번째 땅에 있는 나무에 대해 양분을 먹을 수 있으면 먹고 없으면 죽는다.
		for (int j = 1; j <= N; j++) {
			int size = trees[i][j].size();
			while(size--) {
				int curr = trees[i][j].front();
				trees[i][j].pop_front();

				if (land[i][j] >= curr) {
					land[i][j] -= curr;
					trees[i][j].push_back(curr + 1);
				}
				else {					//죽을 경우 나이의 절반이 양분으로 남음
					dead[i][j] += (curr / 2);
					num--;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {		//summer: spring에 죽은 나무들을 토지 양분으로
		for (int j = 1; j <= N; j++) {		//죽은 나무의 양분 빼먹기
			land[i][j] += dead[i][j];
			dead[i][j] = 0;
		}
	}
}

void fw() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			int size = trees[i][j].size();
			for (int k = 0; k < size; k++) {

				if (trees[i][j][k] % 5 == 0) {		//5의 배수인 나무에 대해, 8가지 방향에 새로운 나무 심기
					for (int l = 0; l < 8; l++) {		
						int r = i + around[l][0], c = j + around[l][1];
						if (r < 1 || r > N  || c < 1 || c > N)
							continue;

						trees[r][c].push_front(1);
						num++;
					}
				}
			}

			land[i][j] += A[i][j];	//winter: 로봇이 양분주기(fall과 겹치는 부분이 없어서 한 for문으로 끝냄)
		}
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			land[i][j] = 5;
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		num++;
		trees[r][c].push_back(age);
	}

	while(K--) {
		ss();
		fw();
	}
	cout << num;
}
