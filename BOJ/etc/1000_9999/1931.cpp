#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second)
		return A.first < B.first;      //끝시간이 같으면 시작시간 빠른 순으로
	return A.second < B.second;
}

int main() {
	int N, count = 0;
	cin >> N;
	vector<pair<int, int>> meetings;	//회의 시작 시간, 회의 끝 시간

	for (int i = 0; i < N; i++) {
		pair<int, int> temp;
		cin >> temp.first >> temp.second;		
		meetings.push_back(temp);
	}

	sort(meetings.begin(), meetings.end(), compare);	//끝시간을 우선으로 정렬
	
	int endtime = 0;
	for (int i = 0; i < meetings.size(); i++) {
        //이전 끝시간보다 현 시작시간이 같거나 늦으면 회의 진행 가능
		if (meetings[i].first >= endtime) {
			count++;
			endtime = meetings[i].second;
		}
	}

	cout << count;
}
