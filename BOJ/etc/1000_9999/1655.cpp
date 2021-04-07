#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, input;
priority_queue<int, vector<int>, less<int>> small;		//최대힙
priority_queue<int, vector<int>, greater<int>> big;		//최소힙

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;

	while (N--) {
		cin >> input;

		small.push(input);
		if (small.size() > big.size() + 1) {
			big.push(small.top());
			small.pop();
		}
		else if (big.size() > 0 && small.size() <= big.size() + 1 && small.top() > big.top()) {
			big.push(small.top());
			small.pop();
			small.push(big.top());
			big.pop();
		}

		cout << small.top() << "\n";
	}
}
