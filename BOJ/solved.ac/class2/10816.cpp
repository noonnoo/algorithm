#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	vector<int> cards;
	int N, M;
	cin >> N;

	while (N--) {
		int card;
		cin >> card;
		cards.push_back(card);
	}
	sort(cards.begin(), cards.end());

	cin >> M;
	while (M--) {
		int card;
		cin >> card;

		vector<int>::iterator lower, upper;
		lower = lower_bound(cards.begin(), cards.end(), card);
		upper = upper_bound(cards.begin(), cards.end(), card);

		cout << upper - lower << " ";
	}
}
