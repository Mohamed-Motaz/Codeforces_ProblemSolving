#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x, y, available, counter = 0, price;
	vector <long long> canDo;
	cin >> x >> available;


	for (int i = 1; i <= x; i++) {
		bool tradeDone = false;
		cin >> y;
		for (int j = 1; j <= y; j++) {
			cin >> price;
			if (available > price) {
				tradeDone = true;
			}
		}
		if (tradeDone) {
			canDo.push_back(i);
			counter++ ;
		}

	}

	cout << counter << endl;
	sort(canDo.begin(), canDo.end());
	for (int i = 0; i < canDo.size(); i++) {
		cout << canDo[i] << " ";
	}
}