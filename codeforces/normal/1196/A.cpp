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
		ll a, b, c;
		cin >> a >> b >> c;
		cout << (a + b + c) / 2 << endl;
	}
}