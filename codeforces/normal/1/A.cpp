#include <bits/stdc++.h>

using namespace std;


int main() {

	long long x, y, a, counter = 0;
	cin >> x >> y >> a;

	long long fitX = x / a;
	long long fitY = y / a;

	counter += fitX * fitY;

	if (x * y < a * a) cout << 1;

	else if ((x * y) % (a*a) == 0) cout << (x * y) / a * a;

	else {
		if (x % a != 0) {
			counter += fitY;
		}
		

		if (y % a != 0) {
			counter += fitX;
		}
		

		counter++;
		cout << counter;
	}
}