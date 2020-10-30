#include <iostream>
#include <string>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int ans = 10000;

	if (w - x < ans)
		ans = w - x;
	if (h - y < ans)
		ans = h - y;
	if (x < ans)
		ans = x;
	if (y < ans)
		ans = y;

	cout << ans;
}
