#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    int vector_prd = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (vector_prd > 0)
        cout << 1;
    else if (vector_prd < 0)
        cout << -1;
    else 
        cout << 0;    
}
