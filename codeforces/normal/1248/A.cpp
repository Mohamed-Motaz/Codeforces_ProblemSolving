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
	while (x--) {
		ll y, even = 0, odd = 0; cin >> y;
		while (y--) {
			ll val; cin >> val;
			if (val % 2 == 0)even++;
			else odd++;
		}
		ll z,secondEven = 0, secondOdd = 0; cin >> z;
		while (z--) {
			ll val; cin >> val;
			if (val % 2 == 0)secondEven++;
			else secondOdd++;
		}
		//cout << "even is now: " << even << " " << "odd is now: " << odd << endl;
		cout << even * secondEven + odd * secondOdd << endl;
		
		
	}
}