#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	ll x, counter= 0, zeroCounter = 0;
	ll sum = 1;
	ll negatives = 0;
	vector<ll> nums;
	cin >> x;
	
	while (x--) {
		
		ll val; cin >> val;

		if (val < 0) {
			
			counter += abs(val) - 1;
			val = -1;
		}
		else if (val > 0) {
			counter += abs(val - 1);
			val = 1;
		}
		else {
			zeroCounter++;
		}
		sum *= val;

	}
	if (sum < 0) {
		cout << counter + 2;
	}else cout << counter + zeroCounter;
}