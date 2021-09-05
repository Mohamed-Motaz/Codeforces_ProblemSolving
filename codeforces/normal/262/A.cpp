#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

long long total = 0;
long long succesful = 0;


int main() {

	long long x, y, counter = 0;
	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		long long init = 0;  string s;
		bool found = true;
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '4' || s[j] == '7') init++;
			
		}

		if (init <= y) counter++;
	}
	cout << counter << endl;

}