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
		ll n, y; cin >> n >> y;
		ll mxm = 0; 
		bool found = false, foundPerfect = false;; ll num;
		while (n--) {
			ll val; cin >> val;
			if (val > mxm) mxm = val;
			if (y% val == 0 && val != 1) {
				found = true; num = y / val;
			}
			if (val == y) foundPerfect = true;
		}
		if (foundPerfect) {
			cout << 1 << endl; continue;
		}

		ll sum = ceil((float)y / (float)mxm);
		if (found && num < sum) {
			cout << num << endl; continue;
		}
		cout << max((ll)2, sum) << endl;

	}
}