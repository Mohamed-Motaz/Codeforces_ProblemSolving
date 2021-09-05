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
		ll siz, dis; cin >> siz >> dis;
		vector<ll> normal;
		for (int i = 0; i < siz; i++) {
			ll val; cin >> val;
			normal.push_back(val);
		}
		vector<ll> distinct;
		for (int i = 0; i < dis; i++) {
			ll val; cin >> val;
			distinct.push_back(val);
		}

		set<ll> notSorted;

		for (int i = 0; i < siz - 1; i++) {
			if (normal[i] > normal[i+1]) {
				notSorted.insert(i + 1);
				for (int j = i + 1; j < siz - 1; j++) {
					if (normal[i] > normal[j]) {
						notSorted.insert(j);
					}
					else break;
				}
			}
		}
		/*cout << endl;
		for (auto elem : notSorted) {
			cout << elem << " ";
		}
		cout << endl;*/
		bool done = true;
		for (auto elem : notSorted) {
			bool found = false;
			for (int i = 0; i < dis; i++) {
				if (elem == distinct[i]) {
					found = true;
				}
			}
			if (!found) {
				cout << "NO" << endl;
				done = false;
				break;
			}
		}
		if (done) cout << "YES" << endl;
	}
}