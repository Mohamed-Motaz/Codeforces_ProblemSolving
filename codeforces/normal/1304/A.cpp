#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll n;
	cin >> n;

	while (n--) {
		ll x, y, a, b, counter = 0;
		//bool flag = false;
		cin >> x >> y >> a >> b;

		if ((x - y) % (a + b) == 0) {
			cout << abs((x - y) / (a + b));
		}
		else {
			cout << -1;
		}
		cout << endl;
	}
	
	
}