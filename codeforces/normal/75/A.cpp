#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;


int main() {

	string s, t;
	cin >> s;
	cin >> t;
	long long temp1 = stoll(s), temp2 = stoll(t);
	long long temp3 = temp1 + temp2;
	//cout << temp3 << endl;
	string temp3String = to_string(temp3);
	for (int i = 0; i < s.size(); i++) {

		if (s[i] == '0') {
			s.erase(s.begin() + i); i--;
		}

	}for (int i = 0; i < t.size(); i++){

		if (t[i] == '0') {
			t.erase(t.begin() + i); i--;
		}
		
	}
	for (int i = 0; i < temp3String.size(); i++) {
		if (temp3String[i] == '0') {
			temp3String.erase(temp3String.begin() + i); i--;
		}
	}
	long long answer = stoll(s) + stoll(t);
	/*cout << s << " " << t << endl;
	cout << answer << " " << stoll(temp3String) << endl;*/
	
	if (answer == stoll(temp3String)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO";
	}
}