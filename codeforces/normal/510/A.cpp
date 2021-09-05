#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x, y, initial1 = 2, initial2 = 4;
	bool right = true;
	cin >> x >> y;

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (i % 2 != 0) {
				cout << "#";
			}
			else if (i == initial1) {
				for (int q = 0; q < y; q++) {
					if (q == y - 1) {
						cout << "#";
					}
					else {
						cout << ".";
					
					}
				}
				initial1 += 4;
				break;
			}
			else if (i == initial2) {
				for (int q = 0; q < y; q++) {
					if (q == 0) {
						cout << "#";
					}
					else {
						cout << ".";

					}
				}
				initial2 += 4;
				break;
			}
		}
		cout << endl;
	}

	
}