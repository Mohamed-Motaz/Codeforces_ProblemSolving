#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x, y, maxdifference = -1, price, difference, index;
	vector<long long> prices;
	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		cin >> price;
		prices.push_back(price);
	}

	for (int i = 1; i < x; i++) {
		difference = prices[i - 1] - prices[i] ;
		if (difference > maxdifference) {
			maxdifference = difference;
			index = i;
		}
	}

	if (maxdifference - y >= 0) {
		cout << maxdifference - y;
	}
	else cout << 0;

}