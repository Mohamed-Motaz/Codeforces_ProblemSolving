#include <bits/stdc++.h>

using namespace std;


int main() {

	long long x;
	map<long long, long long> mp = {
		 {1, 2}, 
		 {7, 3}, 
	};
	
	cin >> x;

	for (int i = 0; i < x; i++) {
		long long value, counter;
		vector<long long> num;
		cin >> value;
		counter = value;

		while (value > 0) {

			if (value == 3) {
				num.push_back(7);
				value -= 3;
			}
			if (value >= 2) {
				num.push_back(1);
				value -= 2;
			}

		}

		for (int i = num.size() - 1; i >= 0; i--) {
			cout << num[i];
		}
		cout << endl;
	}
	
}