#include <bits/stdc++.h>

using namespace std;



int main() {
	
	long long x, a,  b, counter = 0, temp;
	long long arr[] = { 9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999 };
	cin >> x;
	
	for (int i = 0; i < x; i++) {
		counter = 0;
		cin >> a >> b;

		

		for (int j = 0; j < 10; j++) {
			if (b >= arr[j]) {
				counter++;
			}
			else {
				break;
			}
		}

		
		temp = counter * a;
		cout << temp << endl;
	}
}