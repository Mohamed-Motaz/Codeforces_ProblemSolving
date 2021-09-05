#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x, y;
	char numbers[107][107];
	ll arr[107] = {};
	cin >> x >> y;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> numbers[i][j];
		}
	}
	
	for (int i = 0; i < y; i++) {
		char maxi = '0';
		for (int j = 0; j < x; j++) {
			//cout << numbers[j][i] << " ";
			if (numbers[j][i] > maxi) {
				maxi = numbers[j][i];
				
			}
		}
		//cout << maxi << endl;
		for (int j = 0; j < x; j++) {
			if (numbers[j][i] == maxi) {
				arr[j]++;
				
			}
		}
	}

	ll counter = 0;
	for (int i = 0; i < 107; i++) {
		if (arr[i] > 0) counter++;
	}

	cout << counter;
}