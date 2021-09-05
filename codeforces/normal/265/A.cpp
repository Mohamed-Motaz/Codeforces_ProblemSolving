#include <bits/stdc++.h>

using namespace std;



int main() {

	string s, t;
	long long position = 0;
	cin >> s; 
	cin >> t;

	for (int i = 0; i < t.size(); i++) {
		if (t[i] == s[position]) position++;
	}

	cout << position + 1;
	
}