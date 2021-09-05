#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x; cin >> x;
	while (x--) {
		ll a, b;
		cin >> a >> b;
		if (a == b) {
			cout << 0 << endl; continue;
		}
		if (a > b) {
			if ((a - b) % 2 == 0) {
				cout << 1 << endl;
				continue;
			}
			cout << 2 << endl;
			continue;
		}
		else {
			if ((a - b) % 2 != 0) {
				cout << 1 << endl;
				continue;
			}
			cout << 2 << endl;
			continue;
		}
	}
}