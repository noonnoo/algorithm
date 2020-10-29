#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	deque<int> q;

	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			int tmp;
			cin >> tmp;
			q.push_front(tmp);
		}
		else if (cmd == "push_back") {
			int tmp;
			cin >> tmp;
			q.push_back(tmp);
		}
		else if (cmd == "pop_front") {
			if (q.empty())
				cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (q.empty())
				cout << -1 << "\n";
			else {
				cout << q.back() << "\n";
				q.pop_back();
			}
		}
		else if (cmd == "front") {
			if (q.empty())
				cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
			}
		}
		else if (cmd == "back") {
			if (q.empty())
				cout << -1 << "\n";
			else {
				cout << q.back() << "\n";
			}
		}
		else if (cmd == "empty") {
			cout << q.empty() << "\n";
		}
		else if (cmd == "size") {
			cout << q.size() << "\n";
		}
	}
}
