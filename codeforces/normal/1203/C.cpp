#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int main() {


	long long x, counter = 0, myGcd = 0;
	cin >> x;

	for (int i = 0; i < x; i++) {
		long long val ,prev;
		cin >> val;
		
		
		myGcd = gcd(myGcd, val);
		//cout << myGcd << endl;
	}
	
	for (int i = 1; i <= sqrt(myGcd); i++) {
		if (myGcd % i == 0) {
			if (myGcd / i == i) counter++;
			else counter += 2;
		}
	}

	cout << counter;
}