#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"

using namespace std;

ll x, y;
ll all[20][1000007];
bool solve(ll val, ll tmp2) {
	
	
	if (val < 10)
		if (val == tmp2) return true;
		else return false;

	ll tmp = 1;
	while (val) {
		if (val % 10 != 0) tmp *= val % 10;
		val /= 10;
	}
	solve(tmp, tmp2);


}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for (int i = 1; i < 10; i++) {
		ll answer = 0;
		for (int j = 1; j < 1000002; j++) {
			if (solve(j, i)) answer++;
			all[i][j] = answer;
		}

	}
	cin >> x;

	while (x--) {
		ll l, r, counter = 0;
		cin >> l >> r >> y;

		cout << all[y][r] - all[y][l - 1] << endl;
	}
	
}


///