#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;


int main() {

	long long x;
	cin >> x;
	if (x % 4 == 1) {
		cout << 0 << " A";
	}
	else if (x % 4 == 3) {
		cout << 2 << " A";
	}
	else if (x % 4 == 2) {
		cout << 1 << " B";
	}
	else {
		cout << 1 << " A";
 	}


}