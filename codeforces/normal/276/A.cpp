//
#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int main() {
 
	long long x, timeCoach, timeToEnjoy, fullJoy, maximumJoy = -1000000000;
 
	cin >> x >> timeCoach;
 
	for (int i = 0; i < x; i++) {
		cin >> fullJoy >> timeToEnjoy;
 
		if (timeCoach >= timeToEnjoy) {
			if (fullJoy > maximumJoy) maximumJoy = fullJoy;
		}
		else {
			long long tempJoy = fullJoy - (timeToEnjoy - timeCoach);
			if (tempJoy > maximumJoy) maximumJoy = tempJoy;
		}
	}
 
	cout << maximumJoy;
}