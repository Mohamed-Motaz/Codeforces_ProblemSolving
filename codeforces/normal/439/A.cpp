#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	ll x, y, sum = 0;
	vector<ll> numbers;
	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		ll val;
		cin >> val;
		numbers.push_back(val);
		sum += val;
	}
	if (sum + (x - 1) * 10 > y) {
		cout << -1; return 0;
	}
	ll total = 0;
	
	total += ((x - 1) * 10)/5;
	sum += (x - 1) * 10;
	total += (y - sum) / 5;
	cout << total;
}