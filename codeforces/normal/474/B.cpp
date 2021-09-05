#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;
ll solve(vector<ll> vec, ll size, ll val) {
	ll start = 0, end = size - 1;
	ll mid = (start + end) / 2;
	ll answer = 0;

	while (start <= end) {

		if (val < vec[mid]) {
			end = mid - 1;
			answer = mid;
		}
		else if (val > vec[mid]) {
			start = mid + 1;
			
		}
		else {
			answer = mid;
			break;
		}

		mid = (start + end) / 2;
	}



	return answer + 1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	
	ll x; cin >> x;
	vector<ll> worms;
	for (int i = 0; i < x; i++) {
		ll val; cin >> val;
		if (i == 0) {
			worms.push_back(val); continue;
		}
		worms.push_back(val + worms[i - 1]);
	}
	ll y; cin >> y;
	vector<ll> juicy;
	map<ll, ll> mp;
	for (int i = 0; i < y; i++) {
		ll val; cin >> val;
		cout << (lower_bound(worms.begin(), worms.end(),val) - worms.begin()) + 1 << endl;
		
	}
	
	
}