#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string s = "hello";
	ll index = 0;
	string t; 
	cin >> t;

	if (t.size() < s.size()) {
		cout << "NO"; return 0;
	}
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == s[index]) {
			index++;
		}
		if (index == 5) {
			cout << "YES"; return 0;
		}
	}
	cout << "NO";
}