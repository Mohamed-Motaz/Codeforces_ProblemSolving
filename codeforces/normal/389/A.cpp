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
	vector<ll> vec;
	cin >> x;

	while (x--) {
		ll val; cin >> val;
		vec.push_back(val);
	}

	

	while (true) {
		
		sort(vec.begin(), vec.end());
		if (vec[vec.size() - 1] == vec[0]) break;

		for (int i = vec.size() - 1; i >= 1; i--) {
			if (vec[i] > vec[i - 1]) {
				vec[i] = vec[i] - vec[i - 1];
			}
		}

	}
	ll counter = 0;

	for (auto elem : vec) {
		//cout << elem << ' ';
		counter += elem;
	}
	cout << counter << endl;
}