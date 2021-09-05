#include <bits/stdc++.h>

using namespace std;



int main() {

	string s, t;
	long long counter1 = 0, counter2 = 0;
	bool done = false;
	cin >> s >> t;

	for (int i = 0; i < s.size(); i++) {
		s[i] = tolower(s[i]);
		t[i] = tolower(t[i]);

		counter1 += s[i];
		counter2 += t[i];

		if (counter1 > counter2) {
			cout << 1; 
			done = true;
			break;
		}
		else if (counter2 > counter1) {
			cout << -1;
			done = true;
			break;
		}
		
	
	}

	if (!done) { 
			cout << 0;
		}

}