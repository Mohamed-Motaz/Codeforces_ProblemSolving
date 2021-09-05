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
	vector<ll> boys;
	for (int i = 0; i < x; i++) {
		ll val; cin >> val;
		boys.push_back(val);
	}
	ll y; cin >> y;
	vector<ll> girls;
	for (int i = 0; i < y; i++) {
		ll val; cin >> val;
		girls.push_back(val);
	}
	sort(boys.begin(), boys.end());
	sort(girls.begin(), girls.end());
	ll counter = 0, indexFound = 0;
	if (girls >= boys) {
		for (int i = 0; i < y; i++) {
			bool found = false;
			for (int j = indexFound; j < x; j++) {
				if (girls[i] == boys[j] || abs(girls[i] - boys[j]) == 1) {
					found = true;
					indexFound = ++j; break;
				}
			}
			if (found) counter++;
		}
	}
	else {
		for (int i = 0; i < x; i++) {
			bool found = false;
			for (int j = indexFound ; j < y; j++) {
				if (boys[i] == girls[j] || abs(boys[i] - girls[j]) == 1) {
					found = true;
					indexFound = ++j; break;
				}
			}
			if (found) counter++;
		}
	}
	cout << counter;
}