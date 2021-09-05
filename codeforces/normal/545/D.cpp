#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	multiset<ll> nums;
	ll x; cin >> x;

	while (x--) {
		ll val; cin >> val;
		nums.insert(val);
	}
	ll sum = 0, counter = 0;
	for (auto elem : nums) {
		if (elem >= sum) {
			counter++;
			sum += elem;
		}
		
	}
	cout << counter;
}