#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	
	vector<pair<ll, ll>> st;
	ll x; cin >> x;

	while (x--) {
		pair<ll, ll> temp;
		cin >> temp.first >> temp.second;
		st.push_back(temp);
	}
	sort(st.begin(), st.end());
	bool flag = false;
	for (int i = 1; i < st.size(); i++) {
		if (st[i].second < st[i - 1].second && st[i].first != st[i - 1].first) {
			flag = true; break;
		}
	}
	if (flag) cout << "Happy Alex";
	else cout << "Poor Alex";
}