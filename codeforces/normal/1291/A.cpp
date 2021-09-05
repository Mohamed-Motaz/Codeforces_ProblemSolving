#include <bits/stdc++.h>

using namespace std;

string removezero(string s) {
	bool found = false;
	long long i = 0;
	while (s[i] == '0') {
		s.erase(s.begin() + i);
		
	}
	return s;
}

int main() {

	
	long long x; 
	cin >> x;

	for (int i = 0; i < x; i++) {
		long long value ,sum = 0;
		map<long long, long long> mp;
		string s;
		cin >> value;
		cin >> s;

		for (int j = value - 1; j >= 0; j--) {
			long long val = (int)s[j];
			if (val % 2 == 0) {
				s.pop_back();
			}
			else {
				break;
			}
		}
		if (s.size() == 0) {
			cout << -1 << endl;
			continue;
		}
		//cout << "new s is: " << s << endl;

		for (int j = 0; j < value; j++) {
			long long val = (int)s[j];
			sum += val;

		}
		if (sum % 2 == 0) {
			
			cout << removezero(s) << endl;
			continue;
		}
		bool found = false;
		for (int j = 0; j < s.size() - 1; j++) {
			long long val = (int)s[j];
			if (val % 2 != 0) {
				s.erase(s.begin() + j);
				
				cout << removezero(s) << endl;
				found = true;
				break;
			}
		}

		if (!found) {
			cout << -1 << endl;
			continue;
		}
		

	}
}