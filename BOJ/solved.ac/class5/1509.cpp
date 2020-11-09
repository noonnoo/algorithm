#include <iostream>
#include <string>
using namespace std;

string str;
bool DP[2501][2501];
int cnt[2501];

void get_palindrome(int &size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i + 2; j++) {
			if (i <= j)
				DP[i][j] = 1;
			else if (DP[i - 1][j + 1] == true && str[i] == str[j])
				DP[i][j] = 1;
			else
				DP[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> str;
	int size = str.size();

	get_palindrome(size);

	cnt[0] = 1;
 	for (int i = 1; i < size; i++) {
		cnt[i] = 1e9;
		for (int j = 0; j < i + 1; j++) {
			if (DP[i][j]) {
				if (j == 0 && cnt[i] > 1)
					cnt[i] = 1;
				else if (cnt[i] > cnt[j - 1] + 1)
					cnt[i] = cnt[j - 1] + 1;
			}
		}
	}

	cout << cnt[size - 1];
}
