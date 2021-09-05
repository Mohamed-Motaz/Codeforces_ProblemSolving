#include <bits/stdc++.h>

using namespace std;



int main() {

	string s;
	
	map<char, long long> frequency;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		frequency[s[i]]++;
	}

	if (frequency.size() % 2 == 0) cout << "CHAT WITH HER!";
	else cout << "IGNORE HIM!";
	
}