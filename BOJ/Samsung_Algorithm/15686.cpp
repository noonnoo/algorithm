#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> chicken;		//input으로 들어온 치킨집 위치
vector<pair<int, int>> home;		//input으로 들어온 집 위치(매개변수 주고받기 힘들어서 글로벌로 둠)
vector<vector<int>> combs;          //치킨집 조합

void combination(vector<int> comb, int N, int M, int target, int index) {
	if (index == M) {										//index에 도달하면 한개의 조합 생성됨
		combs.push_back(comb);
	}
	else if (target == N + 1) {								//M개보다 숫자를 적게 뽑은 경우
		return;
	}
	else {
		comb[index] = target - 1;							//target은 인덱스보다 1 크기 때문에 빼줌
		combination(comb, N, M, target + 1, index + 1);		//target을 뽑는 경우
		combination(comb, N, M, target + 1, index);			//target을 뽑지 않는 경우
	}
}


int solve(int M) {
	vector<int> comb(M, 0);
	combination(comb, chicken.size(), M, 1, 0);
	vector<int> dist_sum(combs.size(), 0);

	for (int i = 0; i < combs.size(); i++) {				//치킨집 조합들에 대해
		for (int k = 0; k < home.size(); k++) {				//각각의 집들이 갖는 min값을 더해서 치킨집 조합들이 갖는 최소 치킨거리 구함
			int min = 1000;
			for (int j = 0; j < M; j++) {
				int dist = abs(chicken[combs[i][j]].first - home[k].first) + abs(chicken[combs[i][j]].second - home[k].second);
				if (min > dist)
					min = dist;
			}
			dist_sum[i] += min;
		}
	}

	int min = 2147483647;
	for (int i = 0; i < dist_sum.size(); i++) {
		if (min > dist_sum[i])
			min = dist_sum[i];
	}
	return min;												//치킨거리중 최솟값 반환

}

int main() {
	int N, M, temp;
	cin >> N >> M;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
			cin >> temp;

			if (temp == 1)
				home.push_back(make_pair(i, j));
			else if (temp == 2)
				chicken.push_back(make_pair(i, j));
		}
	
	cout << solve(M);
}
