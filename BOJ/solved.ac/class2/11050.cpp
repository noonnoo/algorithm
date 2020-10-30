#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	if (K == 0)
		cout << 1;
	else {
		int ans = 1;
		for (int i = 1; i <= K; i++) 
			ans *= (N - i + 1);

		for (int i = 1; i <= K; i++)
			ans /= i;

		cout << ans;
	}
}
