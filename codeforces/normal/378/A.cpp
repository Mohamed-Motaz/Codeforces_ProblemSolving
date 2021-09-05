#include <bits/stdc++.h>

using namespace std;



int main() {

	long long a, b, wins1, draw, wins2, drawValue;
	cin >> a >> b;

	draw = (abs(a - b) % 2 == 0) ? 1 : 0;
	drawValue = abs(a - b) / 2 + min(a,b);
	if (a == b) {
		wins1 = 0;
		wins2 = 0;
		draw = 6;
	}
	else if (a > b) { // a is closer to 6
		
		wins2 = drawValue;
		wins1 = 6 - wins2;
		if (draw) wins2--;
	}
	else {            //b is closer to 6
		wins1 = drawValue;
		wins2 = 6 - wins1;
		if (draw) wins1--;
	}

	











	cout << wins1 << " " << draw << " " << wins2;
}