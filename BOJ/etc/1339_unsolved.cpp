#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int N, maxi = 0, num = 9, result = 0;
vector<int> alphabet(26, -1);
vector<string> words;
bool occupied[10];

bool cmp(string str1, string str2) {
	return str1.size() > str2.size();
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	words.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}
	sort(words.begin(), words.end(), cmp);

	maxi = words[0].size();
	while (maxi) {
		for (int i = 0; i < N; i++) {
			int wsize = words[i].size();
			if (wsize >= maxi && alphabet[words[i][wsize - maxi] - 65] == -1) {
				alphabet[words[i][wsize - maxi] - 65] = num--;
			}
			else {
				maxi--;
				break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int wsize = words[i].size();
		for (int j = 0; j < wsize; j++) {
			result += alphabet[words[i][j] - 65] * pow(10, wsize - j - 1);
		}
	}

	cout << result;
}
