#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>


using namespace std;



int main() {
	
	int x, hr, mins;

	cin >> x;

	for (int i = 0; i < x; i++) {
		cin >> hr >> mins;

		if (hr == 23) {
			cout << 60 - mins << endl;
		}
		else {
			cout << (24 - hr - 1) * 60 + (60 - mins) << endl;
		}
	}
}