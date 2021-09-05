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

	while (x--) {
		ll k, n; cin >> k >> n;
		ll oddsCounter = 0;
		vector<ll> stored;

		for (int i = 0; i < k; i++) {
			ll val; cin >> val;
			if (val % 2 != 0) {
				oddsCounter++;
				
			}stored.push_back(val);
		}
		if (oddsCounter < n || oddsCounter % 2 != n % 2) {
			cout << "NO" << endl; continue;
		}
		cout << "YES" << endl;
		ll sum = 0;
		for (int i = 0; i < k; i++) {
			sum += stored[i];

			if (sum % 2 != 0 && n > 1) {
				cout << i + 1<< " ";
				sum = 0;
				n--;
			}
		}
		cout << k << endl;
	}
}