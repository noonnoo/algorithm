#include <iostream>
#include <string>
using namespace std;

string DP[10001];

string bigSum(string num1, string num2) {
	string result = "";
	int temp = 0;
	
	for (int i = num2.size() - 1, j = num1.size() - 1; i >= 0; i--, j--) {
		result = to_string((temp + (num1[j] - '0') + (num2[i] - '0')) % 10) + result;
		temp = (temp + (num1[j] - '0') + (num2[i] - '0')) / 10;
	}

	if (num1.size() != num2.size())
		result = to_string(stoi(num1.substr(0, num1.size() - num2.size())) + temp) + result;
	else if(temp != 0)
		result = to_string(temp) + result;

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
