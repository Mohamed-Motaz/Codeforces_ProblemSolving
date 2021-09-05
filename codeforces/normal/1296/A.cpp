#include <bits/stdc++.h>

using namespace std;


int main() {

	long long x;
	cin >> x;

	for (int i = 0; i < x; i++) {
		long long value , evenCounter = 0, oddCounter = 0;
		cin >> value;
		//vector<long long> numbers;

		for (int j = 0; j < value; j++) {
			long long val;
			cin >> val;
			if (val % 2 == 0) evenCounter++;
			else oddCounter++;

		}
			if (oddCounter == 0) cout << "NO" << endl;
			else {
				if (evenCounter == 0 && value % 2 == 0) cout << "NO" << endl;
				else cout << "YES" << endl;
			}
	}

}