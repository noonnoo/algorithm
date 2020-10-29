#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;

	while (cin >> N) {
		if (N == "0")
			break;
		int size = N.size(), half = size-- / 2;
		bool yes = true;
		for (int i = 0; i < half; i++) {
			if (N[i] != N[size - i]) {
				yes = false;
				break;
			}
		}

		if(yes)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
}
