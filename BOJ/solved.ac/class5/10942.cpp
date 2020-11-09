#include <iostream>
using namespace std;

int num[2000];
bool DP[2001][2001];
int N, M, n1, n2;

void get_palindrome() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 2; j++) {
			if (i <= j)                    // i == j이거나 i == j+1이면 무조건 1
				DP[i][j] = 1;
			else if (DP[i - 1][j + 1] == true && num[i] == num[j]) 
				DP[i][j] = 1;             //첫과 끝은 자른 부분이 회문이고, 첫과 끝이 같으면 회문
			else
				DP[i][j] = 0;             //나머지는 회문 X
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	get_palindrome();
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		cout << DP[n2 - 1][n1 - 1] << "\n";
	}
}
