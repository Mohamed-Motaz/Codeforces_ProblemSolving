
#include <bits/stdc++.h>

using namespace std;



int main() {
	long long initial, dollars, number;
	cin >> initial >> dollars >> number;
	long long cost = initial;

	for (int i = 2; i <= number; i++) {
		cost += initial * i;
	}

	if (cost <= dollars) {
		cout << 0;
	}
	else {
		cout << cost - dollars;
	}
}