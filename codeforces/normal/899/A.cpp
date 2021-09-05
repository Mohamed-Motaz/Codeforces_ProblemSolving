#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	ll x, counter1 = 0, counter2 = 0;
	cin >> x;

	while (x--) {
		ll val;
		cin >> val;
		if (val == 1) counter1++;
		else counter2++;
	}

	if (counter2 > counter1) {
		cout << counter1;
	}
	else cout << counter2 + (counter1 - counter2) / 3;
}