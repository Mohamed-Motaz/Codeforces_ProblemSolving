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
		ll n, m; cin >> n >> m;
		string s; cin >> s;
		map<char, ll> freq;
		while (m--) {
			ll val; cin >> val;
			string temp = s.substr(0, val);
			//cout << "temp is: " << temp << endl;
			for (auto elem : temp) {
				freq[elem]++;
			}
		}
		for (auto elem : s) {
			freq[elem]++;
		}
		for (int i = 0; i < 26; i++) {
			cout << freq['a' + i] << " ";
		}
		cout << endl;
	}
}