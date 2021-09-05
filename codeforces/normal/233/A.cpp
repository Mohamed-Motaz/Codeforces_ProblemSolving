#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x;
	cin >> x;

	if (x % 2 != 0) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= x + 1; i++) {
			if (i % 2 == 0) {
				cout << i << " "; 
			}
			else {
				cout << i - 2 << " ";
			}
		}
		
	}
}