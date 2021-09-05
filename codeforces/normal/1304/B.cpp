#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x, y;
	cin >> x >> y;
	vector<string> pali, palItself, all;
	for (int j = 0; j < x; j++) {
		string s;
		bool isSame = true;
		cin >> s;
		
		all.push_back(s);
	}
	//cout << endl endl endl;
	for (int i = 0; i < all.size(); i++) {
		bool pal = true;
		
		for (int j = 0; j < all.size(); j++) {
			pal = true;
			if (i == j) continue;
			string temp1 = all[i], temp2 = all[j];
			ll start = 0, end = y - 1;
			while (start < y) {
				if (temp1[start] == temp2[end]) {
					start++; end--;
				}
				else {
					pal = false;
					break;
				}
			}
			if (pal) {
				pali.push_back(all[i]);
				all.erase(all.begin() + j);
			}
		}

		//check if word itself is pali
		bool paliItself = true;
		ll start = 0, end = y - 1;
		string word = all[i];
		while (start < end) {
			if (word[start] == word[end]) {
				start++, end--;
			}
			else {
				paliItself = false; break;
			}
		}

		if (paliItself) {
			palItself.push_back(word);
		}
	
	}

	ll size = pali.size() * y * 2;
	if (palItself.size() > 0) size += y;
	cout << size << endl;
	for (auto elem : pali) {
		cout << elem;
	}
	if (palItself.size() > 0) cout << palItself[0];
	for (int i = pali.size() - 1; i >= 0; i--) {
		reverse(pali[i].begin(), pali[i].end());
		cout << pali[i];
	}
	
}