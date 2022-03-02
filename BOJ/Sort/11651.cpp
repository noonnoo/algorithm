#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

void location_sort(int N) {
	vector<pair<int, int>> locations;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		locations.push_back(make_pair(x, y));
	}

	sort(locations.begin(), locations.end(), compare);		//STL의 sort함수 이용

	for (int i = 0; i < N; i++) {
		cout << locations[i].first << " " << locations[i].second << "\n";
	}
}

int main() {
	long long N;
	cin >> N;

	location_sort(N);
}
