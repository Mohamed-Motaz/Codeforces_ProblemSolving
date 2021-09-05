#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x, y, evenCounter = 0, oddCounter = 0;
	vector<long long> myVector;
	cin >> x;

	for (int i = 0; i < x; i++) {
		cin >> y;
		myVector.push_back(y);
		if (y % 2 == 0) evenCounter++;
		if (y % 2 != 0) oddCounter++;


	}

	if (evenCounter > oddCounter) {
		//strange is odd
		for (int i = 0; i < x; i++) {
			if (myVector[i] % 2 != 0) {
				cout << i + 1;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < x; i++) {
			if (myVector[i] % 2 == 0) {
				cout << i + 1;
				break;
			}
		}
	}

	
}