#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> near[5] = { make_pair(-1, 0), make_pair(0, -1), make_pair(0, 1), make_pair(1, 0) };
bool visited[10][10][10][11];	//R과 B가 방문한적 있는 곳 (R의 r,c B의 r,c 순서로 저장)

//0은 위, 1는 왼쪽, 2은 오른쪽, 3은 아래쪽
pair<pair<int, int>, pair<int, int>> move(const vector<vector<char>>& board, pair<int, int>R, pair<int, int> B, int d) {
	pair<pair<int, int>, pair<int, int>> RB;
	int i = near[d].first, j = near[d].second;

	while (board[R.first][R.second] != 'O' && board[B.first][B.second] != 'O'		//R과 B모두 공통으로 움직일수 있을 때까지 움직임
		&& board[R.first + i][R.second + j] != '#' && board[B.first + i][B.second + j] != '#') {
		R.first += i;
		R.second += j;
		B.first += i;
		B.second += j;
	}

	while (board[R.first][R.second] != 'O'		//R이 더 갈 수 있으면 더가게
		&& board[R.first + i][R.second + j] != '#' && !(R.first + i == B.first && R.second + j == B.second)) {
		R.first += i;
		R.second += j;
	}

	while (board[B.first + i][B.second + j] == 'O' || board[B.first][B.second] != 'O' //B가 더 갈 수 있으면 더가게
		&& board[B.first + i][B.second + j] != '#' && !(R.first == B.first + i && R.second == B.second + j)) {
		B.first += i;
		B.second += j;
	}

	RB = make_pair(R, B);
	return RB;
}

int solve(const vector<vector<char>>& board, pair<int, int> R, pair<int, int> B) {		//DFS
	queue<pair<int, int>> rq;	//R과 인접한 칸들
	queue<pair<int, int>> bq;	//R이 rq에서 i번째 위치일 때, B의 위치
	queue<int> moved_num;

	rq.push(R);
	bq.push(B);
	moved_num.push(0);

	while (!rq.empty()) {
		pair<int, int> r_temp = rq.front();	//이번에 방문한 R
		pair<int, int> b_temp = bq.front();	//이번에 방문한 B
		int num = moved_num.front() + 1;

		rq.pop();
		bq.pop();
		moved_num.pop();

		if (visited[r_temp.first][r_temp.second][b_temp.first][b_temp.second])	//이미 해당 부분을 방문했다면 continue
			continue;																		

		visited[r_temp.first][r_temp.second][b_temp.first][b_temp.second] = true;

		for (int i = 0; i < 4; i++) {
			pair<pair<int, int>, pair<int, int>> moved = move(board, r_temp, b_temp, i);	//i방향으로 움직임
			pair<int, int> mr = moved.first;	//움직인 r	
			pair<int, int> mb = moved.second;	//움직인 b

			if (!visited[mr.first][mr.second][mb.first][mb.second]	//움직인 R과 B가 방문한 적이 없고,
				&& (r_temp != mr || b_temp != mb)) {				//원래 R과 B와 같은 위치가 아니라면 확인해보기
				if (board[mb.first][mb.second] == 'O')				//움직인 B가 구멍에 빠지면 continue
					continue;
				else if (board[mr.first][mr.second] == 'O')			//움직인 A가 구멍에 빠지면 return
					return num;
				else {												//어디 빠진게 없으면 다음 경로에 넣어줌
					rq.push(mr);
					bq.push(mb);
					moved_num.push(num);
				}
			}
		}
	}

	return -1;
}

int main() {
	int N, M;
	pair<int, int> R, B;
	cin >> N >> M;
	vector<vector<char>> board(N, vector<char>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'R') {
				R = make_pair(i, j);
				board[i][j] = '.';			//R과 B의 위치는 pair로 확인할 것이기 때문에 보드 상에서는 빼줌
			}
			else if (board[i][j] == 'B') {
				B = make_pair(i, j);
				board[i][j] = '.';
			}
		}
	}

	cout << solve(board, R, B);
}
