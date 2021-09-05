#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

long long arr1[200000];
long long arr2[200000];
map<long long, long long> mp;
int main() {

	long long x;
	cin >> x;

	for (int i = 0; i < x; i++) {
		cin >> arr1[i];
		mp[arr1[i]] = i;
	}

	for (int i = 0; i < x; i++) {
		cin >> arr2[i];
		arr2[i] = mp[arr2[i]];
	}

	/*for (int i = 0; i < x; i++) {
		cout << arr2[i] << endl;
	}*/

	long long mini = arr2[x - 1], counter = 0;
	for (int i = x - 2; i >= 0; i--) {
		if (arr2[i] < mini) {
			mini = arr2[i];
		}
		else {
			counter++;
		}
	}
	cout << counter;

}