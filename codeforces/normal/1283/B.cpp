#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x, candies, kids, counter = 0;

	cin >> x;


	for (int i = 0; i < x; i++) {
		cin >> candies >> kids;

		if (candies % kids == 0 || candies <= kids) {
			cout << candies << endl;
		}
		else {
			long long kidsDivided = kids / 2;

			cout << (candies / kids) * kids + kidsDivided << endl;
		}
	}
}