
#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x, a, b, c, counter = 0, finalCounter = 0;

	cin >> x;

	for (int i = 0; i < x; i++) {
		counter = 0;
		cin >> a >> b >> c;

		if (a == 1) counter++;
		if (b == 1) counter++;
		if (c == 1) counter++;
	
		if (counter >= 2) finalCounter++;
	}
	cout << finalCounter;
}