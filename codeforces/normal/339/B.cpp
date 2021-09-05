#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x, y;
	vector<ll> nums;
	cin >> x >> y;
	while (y--) {
		ll val; cin >> val;
		nums.push_back(val);
	}
	ll counter = nums[0] - 1;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] < nums[i - 1]) {
			counter += x - nums[i - 1];
			counter += nums[i];
		}
		else {
			counter += nums[i] - nums[i - 1];
		}
	}
	cout << counter;
}