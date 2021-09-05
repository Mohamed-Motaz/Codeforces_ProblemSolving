#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x, value, minimum = 1000000, maxDifficulty, currentDifficulty, maximum, counter = 1, toCompare;
	vector<long long> valuesTaken;
	vector<long long> copy;
	cin >> x;

	for (int i = 0; i < x; i++) {
		cin >> value;
		valuesTaken.push_back(value);
	}

	toCompare = valuesTaken[x - 1];
	counter = 1;
	for (int i = x - 2; i > 0 ; i--) {
		copy = valuesTaken;
		copy.erase(copy.begin() + counter);
		maximum = -1;

		
		for (int j = copy.size() - 1; j >= 1; j--) {
			currentDifficulty = copy[j] - copy[j - 1];
			if (currentDifficulty > maximum) maximum = currentDifficulty;
				
		}

		if (maximum < minimum) minimum = maximum;
		
				
			
		
		counter++;
		
		
	}
	cout << minimum <<endl;
}