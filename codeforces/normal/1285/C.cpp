#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;
ll getLCM(ll i, ll x) {
	//cout << gcd(i, x / i) << endl;
	return x * gcd(i, x / i);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x;
	cin >> x;
	
	for (int i = sqrt(x); i >= 1; i--) {


		/*if (x % i == 0 ) {
			cout << i << " " << x / i << endl;
			cout << getLCM(i, x) << endl;
		}*/
		
		if (x % i == 0 && getLCM(i,x) == x) {
			cout << i << " " << x / i;
			return 0;
		}
	}


}