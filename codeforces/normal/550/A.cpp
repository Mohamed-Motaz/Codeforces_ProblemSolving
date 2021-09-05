
#include <bits/stdc++.h>

using namespace std;



int main() {
	
	string s, first = "AB", second = "BA";
	vector<int> firstsOccurence;
	vector<int> secondsOccurence;

	bool found = false;
	cin >> s;

	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == first[0] && s[i + 1] == first[1]) {
			firstsOccurence.push_back(i);
		}

		if (s[i] == second[0] && s[i + 1] == second[1]) {
			secondsOccurence.push_back(i);
		}
	}

	sort(firstsOccurence.begin(), firstsOccurence.end());
	sort(secondsOccurence.begin(), secondsOccurence.end());

	if (firstsOccurence.size() > 0 && secondsOccurence.size() > 0) {
		
		if (abs(firstsOccurence[firstsOccurence.size() - 1] - secondsOccurence[0]) >= 2 ||
			abs(secondsOccurence[secondsOccurence.size() - 1] - firstsOccurence[0]) >= 2) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	else {
		cout << "NO";
	}
}