#include <iostream>
#include <string>
using namespace std;

void solve() {
	int H, W, N;
	string ans = "";
	cin >> H >> W >> N;

	if (N % H == 0)			//YY부분 구하기
		ans += to_string(H);
	else
		ans += to_string(N % H);
		
	if (N / H < 9)			//XX부분 구하기
		ans += '0' + to_string(N / H + 1);
	else
		ans += to_string(N / H + 1);

	if (N % H == 0)			//XX부분에서 예외 처리
		ans = to_string(stoi(ans) - 1);

	cout << ans << "\n";
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		solve();
}
