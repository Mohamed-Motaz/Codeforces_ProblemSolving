#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;


int main() {

	long long x; cin >> x;
	
	for (int i = 0; i < x; i++) {
		long long y, sum = 0; 
		cin >> y;

		for (int j = 0; j < y; j++){
			long long temp; cin >> temp;
			sum += temp;
		}
		long long answer = ceil((double)(sum) / (double)(y));
		cout << answer << endl;
	}
}