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
		string s; cin >> s;
		ll max0 = 0; 
		ll zeroCounter = 0;
		bool oneFound = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				if (oneFound) {
					oneFound = false;
					max0 += zeroCounter;
					zeroCounter = 0;
				}
				oneFound = true;
			}
			else if (oneFound) {
				zeroCounter++;
			}
			
		}

		cout << max0 << endl;
	}
}