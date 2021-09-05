#include <bits/stdc++.h>

using namespace std;


int main() {

	long long x, y;
	vector<long long> ladder;
	vector<long long> numbers;
	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		long long value;
		cin >> value;
		numbers.push_back(value);
	}
	bool inc = false, dec = false;
	for (int j = 1; j < numbers.size(); j++) {
		if (numbers[j] - numbers[j - 1] > 0) {
			inc = true;
			if (dec) {
				//cout << j << endl;
				ladder.push_back(j);
				inc = false; dec = false;
				continue;
			}

		}else if (numbers[j] - numbers[j - 1] < 0) {
			dec = true;


		}
		else {
			continue;
		}
	}

	ladder.push_back(numbers.size());

	for (int i = 0; i < y; i++) {
		long long temp1, temp2;
		bool canDo = false;
		cin >> temp1 >> temp2;
		if (abs(temp1 - temp2) == 0 || abs(temp1 - temp2) == 1) {
			cout << "Yes" << endl;
			continue;
		}
		for (auto elem : ladder) {
			if (temp1 < elem && temp2 > elem) {
				break;
			}if (temp1 <= elem && temp2 <= elem) {
				canDo = true;
				break;
			}
		}
	
		if (canDo) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	/*for (int i = 0; i < y; i++) {
		long long temp1, temp2;
		bool inc = false, dec = false ,canDo = true;
		cin >> temp1 >> temp2;
		if (abs(temp1 - temp2) == 0 || abs(temp1 - temp2) == 1) {
			cout << "Yes" << endl;
			continue;
		}

		for (int j = temp1; j < temp2; j++) {
			if (numbers[j] - numbers[j - 1] >= 0) {
				inc = true;
				if (dec) canDo = false;
				
			}if (numbers[j] - numbers[j - 1] < 0) {
				dec = true;
				if (!inc) canDo = false;

			}
		}

		if (canDo) cout << "Yes" << endl;
		else cout << "No" << endl;
	}*/

}