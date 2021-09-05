#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x;
	cin >> x;

	while (x--) {
		ll y, sum = 0, counter = 0; 
		cin >> y;
		map<ll, ll> mp;
		vector<ll> vec;
		for (int i = 0; i < y; i++) {
			
			ll val; cin >> val;
			vec.push_back(val);
			mp[val]++;
			sum += val;
		}
		if (sum != 0 && mp[0] == 0) {
			cout << 0 << endl;
			continue;
		}
		counter += mp[0];
		if (sum + counter == 0) counter++;
		cout << counter << endl;
	}
}