#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x;
	cin >> x;

	
	ll counter = 1;
	while (true) {
		ll p = x + 1;

		while (p != 0) {
			if (abs(p % 10) == 8) {
				cout << counter << endl;
				return 0;
			}
			p /= 10;
		}

		counter++;
		x++;
	}
}