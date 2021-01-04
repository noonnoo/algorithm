#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int N, result = 0, num = 9;
vector<string> words;
pair<int, char> alphabet[26];
int nums[26];

bool cmp(pair<int, char> p1, pair<int, char> p2) {
	return p1.first > p2.first;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	words.resize(N);

	for (int i = 0; i < 26; i++) 
		alphabet[i].second = (char)65 + i;
	
	for (int i = 0; i < N; i++) {
		cin >> words[i];
		
		for (int j = 0; j < words[i].size(); j++) {
			alphabet[words[i][j] - 65].first += pow(10, words[i].size() - j - 1);
		}
	}

	sort(alphabet, alphabet + 26, cmp);

	for (int i = 0; i < 26; i++) {
		if (alphabet[i].first != 0) {
			nums[alphabet[i].second - 65] = num--;
		}
	}

	for (int i = 0; i < N; i++) {
		int wsize = words[i].size();
		for (int j = 0; j < wsize; j++) {
			result += nums[words[i][j] - 65] * pow(10, wsize - j - 1);
		}
	}

	cout << result;
}
