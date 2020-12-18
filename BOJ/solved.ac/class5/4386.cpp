#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

pair<double, double> star[101];

struct cmp {
	bool operator()(pair<double, pair<double, double>> d1, pair<double, pair<double, double>> d2) {
		return d1.first > d2.first;
	}
};

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);

	//숫자가 작은 부모로 병합
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int find(int parent[], int a, int b) {	//서로 같은 부모면 0반환
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b) return 1;
	else return 0;
}

int main() {
	int n, parent[101];
	cin >> n;
	priority_queue<pair<double, pair<double, double>>, vector<pair<double, pair<double, double>>>, cmp> star_dist;

	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		star[i] = { x, y };
		parent[i] = i;
	}	

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = sqrt(pow(star[i].first - star[j].first, 2) + pow(star[i].second - star[j].second, 2));
			star_dist.push({ dist, {i, j} });
		}
	}

	double ans = 0;
	while (!star_dist.empty()) {
		pair<double, pair<double, double>> s1 = star_dist.top();
		star_dist.pop();

		if (!find(parent, s1.second.first, s1.second.second)) {
			ans += s1.first;
			unionParent(parent, s1.second.first, s1.second.second);
		}
	}

	cout << round(ans * 100) / 100;
}
