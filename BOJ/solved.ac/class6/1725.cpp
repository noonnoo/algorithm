#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

ll hist[100001];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;

	ll ans = 0;
	stack<ll> idx;

	for (int i = 0; i < n; i++)
		cin >> hist[i];

	for (int i = 0; i < n; i++) {
		while (!idx.empty() && hist[idx.top()] > hist[i]) {
			ll height = hist[idx.top()];
			ll width = i;
			idx.pop();

			if (!idx.empty())
				width = i - idx.top() - 1;

			if (ans < width * height)
				ans = width * height;
		}
		idx.push(i);
	}

	while (!idx.empty()) {
		ll height = hist[idx.top()];
		ll width = n;
		idx.pop();

		if (!idx.empty())
			width = n - idx.top() - 1;

		if (ans < width * height)
			ans = width * height;
	}

	cout << ans << endl;
}
