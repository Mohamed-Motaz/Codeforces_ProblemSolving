
#include <bits/stdc++.h>

using namespace std;



int main() {
	
	long long x, y, minimum = 0;
	map<long long, long long> numbers;
	cin >> x;

	for (int i = 0; i < x; i++) {
		cin >> y;

		numbers[y]++;
	}
	minimum += numbers[4];

	long long onesCounter = numbers[1];
	long long threesCounter = numbers[3];

	long long minimumOfBoth = min(onesCounter, threesCounter);

	minimum += minimumOfBoth;

	long long onesLeftOver = onesCounter - minimumOfBoth;
	long long threesLeftOver = threesCounter - minimumOfBoth;

	minimum += threesLeftOver;

	minimum += onesLeftOver / 4;

	long long remainderOfOnes = onesLeftOver % 4;

	minimum += remainderOfOnes / 3;

	remainderOfOnes %= 3;

	long long twosCounter = numbers[2];
	minimum += twosCounter / 2;

	long long twosLeftOver = twosCounter % 2;

	if (twosLeftOver + remainderOfOnes >= 1) minimum++;


	cout << minimum;

}