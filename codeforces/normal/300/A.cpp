#include <bits/stdc++.h>

using namespace std;


int main() {

	long long x, negativeCounter = 0;
	vector<long long> numbers;
	vector<long long> pos;
	vector<long long> neg;
	vector<long long> zero;
	cin >> x;

	for (int i = 0; i < x; i++) {
		long long value;
		cin >> value;
		if (value < 0) negativeCounter++;
		if (value == 0) zero.push_back(0);
		else numbers.push_back(value);
	}
	
	if (negativeCounter % 2 == 0) {
		//remove a single negative number so negativeCounter is odd
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] < 0) {
				zero.push_back(numbers[i]);
				numbers.erase(numbers.begin() + i);
				
				break;
			}
		}
	}
	bool done = false;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] < 0 && !done) {
			neg.push_back(numbers[i]);
			done = true;
		}
		else {
			pos.push_back(numbers[i]);
		}
	}


	cout << neg.size() << ' ';
	for (int i = 0; i < neg.size(); i++) cout << neg[i] << ' ';
	cout << endl;

	cout << pos.size() << ' ';
	for (int i = 0; i < pos.size(); i++) cout << pos[i] << ' ';
	cout << endl;

	cout << zero.size() << ' ';
	for (int i = 0; i < zero.size(); i++) cout << zero[i] << ' ';
	cout << endl;
}