#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll counter = 0;
	string s = "RGB";
	while (s.size() < 2000) {
		s += s;
		counter++;
	}
	//cout << s.size() << "  " << counter;
	ll x;
	cin >> x;
	while (x--) {
		ll n, k, indexOfLargestm , maxCounter = 0, counter = 0, firstIndex = 0;
		bool found = false;
		cin >> n >> k;
		string t; cin >> t;
		for (int i = 0; i < n; i++) {
			
			char currentChar = t[i];
			if (!found) {
				if (currentChar == 'R') firstIndex = 0;
				if (currentChar == 'G') firstIndex = 1;
				if (currentChar == 'B') firstIndex = 2;
				found = true;
				counter++;
			}
			else {
				firstIndex++;
				if (currentChar == s[firstIndex]) {
					counter++;
				}
				else {
					if (counter > maxCounter) maxCounter = counter;
					found = false;
					counter = 0;
					i--;
				}
				
			}

		}
		if (counter > maxCounter) maxCounter = counter;
		//cout << maxCounter << endl;
		if (k - maxCounter <= 0) {
			cout << 0;
		}
		else cout << k - maxCounter;
		cout << endl;
	}
	
}