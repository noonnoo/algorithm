#include <iostream>
#include <algorithm>
using namespace std;

int square[1001][1001];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, side_size = 0;
	string line;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			square[i][j] = line[j] - '0';
			if (i > 0 && j > 0 && square[i][j] == 1)
				square[i][j] = min(square[i - 1][j - 1], min(square[i][j - 1], square[i - 1][j])) + 1;

			side_size = max(side_size, square[i][j]);
		}
	}

	cout << side_size * side_size;
}
