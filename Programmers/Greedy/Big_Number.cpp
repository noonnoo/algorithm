#include <string>
#include <vector>

using namespace std;

int ans = 0;

void combination(string number, string comb, int N, int M, int idx) {
	if (comb.size() == M) {
		ans = max(stoi(comb), ans);
		return;
	}
	else if (idx == N) {
		return;
	}
	else {
		combination(number, comb, N, M, idx + 1);
		comb += number[idx];
		combination(number, comb, N, M, idx + 1);
	}
}

string solution(string number, int k) {
	string answer = "";

	combination(number, "", number.size(), number.size() - k, 0);

	answer = to_string(ans);
	return answer;
}
