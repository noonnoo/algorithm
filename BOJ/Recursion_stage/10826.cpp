#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string DP[10001];

string bigSum(string num1, string num2) {
	string result = "";
	int temp = 0;

	if (num2.size() < 18)
		result = to_string(stoll(num2) + stoll(num1));
	else {
		int i = 1;
		for (; i <= floor((double)num2.size() / 18); i++) {
			long long t = stoll(num2.substr(num2.size() - i * 18, 18)) + stoll(num1.substr(num1.size() - i * 18, 18));
			result = to_string((temp + t) % 1000000000000000000) + result;
			
			if (result.size() % 18 != 0) {
				while(18*i != result.size())
					result = '0' + result;
			}
			temp = (temp + t) / 1000000000000000000;
		}

		if (ceil((double)num2.size() / 18)  >= i) {
			long long t = stoll(num1.substr(0, num1.size() - 18 * (i - 1))) + stoll(num2.substr(0, num2.size() - 18 * (i - 1))) + temp;
			result = to_string(t) + result;
		}
		else if (num1.size() != num2.size())
				result = to_string(stoi(num1.substr(0, num1.size() - num2.size())) + temp) + result;
		else if (temp != 0)
			result = to_string(temp) + result;
	}

	return result;
}

void fibonacci(int n) {
	for (int i = 2; i <= n; i++) {
		DP[i] = bigSum(DP[i - 1], DP[i - 2]);
	}

	cout << DP[n];
}

int main() {
	int N;
	cin >> N;

	DP[0] = "0";
	DP[1] = "1";
	fibonacci(N);
}
