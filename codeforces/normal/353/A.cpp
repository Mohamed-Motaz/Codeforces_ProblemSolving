#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;
bool isEven(ll val) {
	return val % 2 == 0;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x, counterUp = 0, counterDown = 0, odds = 0;
	cin >> x; 
	
	for (int i = 0; i < x; i++) {
		ll tmp1, tmp2; cin >> tmp1 >> tmp2;

		if ((isEven(tmp1) && !isEven(tmp2)) || (!isEven(tmp1) && isEven(tmp2))) {
			odds++;
		}

		counterUp+= tmp1,  counterDown += tmp2;
	}
	//cout << counterUp << " " << counterDown << endl;
	if (isEven(counterUp) && isEven(counterDown)) {
		cout << 0;
	}
	else if (!isEven(counterUp) && !isEven(counterDown) && odds > 0) {
		cout << 1;
	}
	else {
		
		cout << -1;
	}

	
}