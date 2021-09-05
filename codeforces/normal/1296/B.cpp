#include <bits/stdc++.h>

using namespace std;


int main() {

	unsigned long long x;
	cin >> x;

	while (x--) {
		unsigned long long value, counter, otherCounter = 0;
		cin >> value;
		counter = value;
		while (value > 0) {
			counter += value / 10;
			otherCounter += value % 10;
			value /= 10;
		}
		while (otherCounter > 0) {
			counter += otherCounter / 10;
			otherCounter /= 10;
		}
	
		cout << counter << endl;
	}

}