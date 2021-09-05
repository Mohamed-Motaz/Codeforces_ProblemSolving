#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x;
	cin >> x;

	while (x--) {
		ll y;
		vector<ll> vec, first, sec;
		
		cin >> y;
		for (int i = 0; i < y * 2; i++) {
			ll val; cin >> val;
			vec.push_back(val);
		}

		sort(vec.begin(), vec.end());

		for (int i = 0; i < y * 2; i++) {
			if (i % 2 == 0) first.push_back(vec[i]);
			else sec.push_back(vec[i]);
		}

		/*cout << endl;

		for (auto elem : first) {
			cout << elem << ' ';
		}cout << endl;
		for (auto elem : sec) {
			cout << elem << ' ';
		}
		cout << endl << endl;*/
		if (y == 2) {
			cout << abs(vec[0] - vec[2]) << endl;
			continue;
		}
		cout << abs(first[y / 2] - sec[y / 2]) << endl;
	}
}