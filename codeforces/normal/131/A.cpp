#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string s;
	cin >> s;
	bool upperCaseOnly = true;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != toupper(s[i])) {
			upperCaseOnly = false; break;
		}
	}


	if (!upperCaseOnly) {
		cout << s;
	}
	else {
		if (s[0] == toupper(s[0])) {
			for (int i = 0; i < s.size(); i++) {

				s[i] = tolower(s[i]);
			}
			cout << s; return 0;
		}
		
		
		for (int i = 0; i < s.size(); i++) {
			
			if (i == 0) s[i] = toupper(s[i]);
			else s[i] =tolower(s[i]);
		}
		cout << s;
	}
}