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
		ll n, d;
		cin >> n >> d;
		vector<ll> nums;

		for (int i = 0; i < n; i++) {
			ll val; cin >> val;
			nums.push_back(val);
		}
		ll counter = nums[0];

		for (int i = 1; i < n; i++) {
			if (nums[i] == 0) continue;
			if (d == 0) continue;
			ll maxVal;
			while (nums[i] > 0) {
				if (i <= d) {
					nums[i]--;
					d-= i;
					counter++;
				}
				else  break;
			}
			
		}
		cout << counter << endl;
	}
}