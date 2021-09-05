#include <bits/stdc++.h>

using namespace std;



int main() {
	
	long long x, counter = 0;
	double n, d;
	bool done;
	cin >> x;


	for (int i = 0; i < x; i++) {
		done = false;
		cin >> n >> d;


		if (n >= d) {
			cout << "yes" << endl;
		}
		else {
			for (int j = 0; j < n; j++) {
				long long val = j + ceil(d / (j + 1));
				
				if (val <= n) {

					cout << "yes" << endl;
					done = true;
					break;
				}

			}
			if (!done) {
				cout << "no" << endl;
			}
		}
	}
}