#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int> st;

	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int tmp; 
			cin >> tmp;
			st.push(tmp);
		}
		else if (cmd == "pop") {
			if (st.empty())
				cout << -1 << "\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (cmd == "top") {
			if (st.empty())
				cout << -1 << "\n";
			else {
				cout << st.top() << "\n";
			}
		}
		else if (cmd == "empty") {
			cout << st.empty() << "\n";
		}
		else if (cmd == "size") {
			cout << st.size() << "\n";
		}
	}
}
