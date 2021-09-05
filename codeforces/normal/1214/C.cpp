#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	stack<char> stck;

	ll x; cin >> x;
	string s; cin >> s;
	if (x % 2 != 0) {
		cout << "NO"; return 0;
	}
	ll counter = 0, temp1 = 0, temp2 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			temp1++;
			stck.push('(');
		}
		else {
			temp2++;
			if (stck.empty()) {
				counter++;
			}
			else {
				stck.pop();
			}
		}
		if (counter > 1) {
			cout << "NO";
			return 0;
		}
	}
	if (temp1 != temp2) {
		cout << "NO"; return 0;
	}
	cout << "YES";
}