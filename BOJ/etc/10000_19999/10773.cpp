#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	stack<int> st;
	int K, result = 0;
	cin >> K;

	while (K--) {
		int tmp;
		cin >> tmp;
		if (tmp != 0) {
			st.push(tmp);
		}
		else if(!st.empty()) {
			st.pop();
		}
	}

	while(!st.empty()) {
		result += st.top();
		st.pop();
	}
	cout << result;
}
