#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans = 0;
vector<int> cards;

void pick_three(int sum, int cnt, int idx) {
	if (cnt == 3) {
		if (M - sum >= 0 && M - sum < M - ans)
			ans = sum;
		return;
	}
	else if (idx == N)
		return;
	
	pick_three(sum, cnt, idx + 1);
	pick_three(sum + cards[idx], cnt + 1, idx + 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int card;
		cin >> card;
		cards.push_back(card);
	}
	sort(cards.begin(), cards.end());

	pick_three(0, 0, 0);
	cout << ans;
}
