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
	vector<ll> tmp1;
	map<ll, ll> nums1;
	for (int i = 0; i < x; i++) {
		ll val; cin >> val;
		nums1[val]++;
		tmp1.push_back(val);
	}
	ll y; cin >> y;
	vector<ll> tmp2;
	map<ll, ll> nums2;
	for (int i = 0; i < y; i++) {
		ll val; cin >> val;
		nums2[val]++;
		tmp2.push_back(val);
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			ll sum = tmp1[i] + tmp2[j];
			if (nums1[sum] == 0 && nums2[sum] == 0) {
				cout << tmp1[i] << " " << tmp2[j];
				return 0;
			}
		}
	}
}