#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x, sum = 0;
	bool possible = false;
	vector<ll> seats;
	cin >> x;

	while (x--) {
		ll val; cin >> val;
		sum += val;
		seats.push_back(val);
	}
	ll toBeat1 = sum/ 2 + 1;
	//cout << toBeat1 << " " << seats[0] << endl;

	vector<ll> agreed = {1};
	ll mySum = seats[0];

	for (int i = 1; i < seats.size(); i++) {
		if (seats[0] >= 2 * seats[i]) {
			agreed.push_back(i + 1);
			mySum += seats[i];
		}
		if (mySum >= toBeat1) {
			possible = true;
			break;
		}
	}

	if (possible) {
		cout << agreed.size() << endl;
		for (auto elem : agreed) {
			cout << elem << " ";
		}
	}
	else {
		cout << 0;
	}
}