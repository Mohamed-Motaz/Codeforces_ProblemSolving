#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	vector<ll> vec;
	ll x; cin >> x;
	for (int i = 0; i < x; i++) {
		ll val; cin >> val;
		vec.push_back(val);
	}
	/*if (x == 1) {
		cout << vec[0]; return 0;
	}*/
	sort(vec.begin(), vec.end());
	ll first = 0, second = 0;

	for (int i = 0; i < vec.size() / 2; i++) {
		first += vec[i];
	}
	for (int i = vec.size() / 2; i < vec.size(); i++) {
		second += vec[i];
	}
	cout << (ll)pow(first, 2) + (ll)pow(second, 2);
}