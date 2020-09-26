#include <iostream>
#include <string>
using namespace std;

double nums[1001];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		int score = 0;
		int t_score = 0;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == 'O') {
				t_score++;
				score += t_score;
			}
			else
				t_score = 0;
		}
		cout << score << "\n";
	}
}
