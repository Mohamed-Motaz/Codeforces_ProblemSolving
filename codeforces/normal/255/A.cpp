
#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x, value, chest = 0, back = 0, biceps = 0, counterChest = 1, counterBack = 3, counterBiceps  =2;
	cin >> x;

	for (int i = 1; i <= x; i++) {
		cin >> value;
		if (i == counterBack) {
			back += value;
			counterBack += 3;
		}else if (i == counterChest) {
			chest += value;
			counterChest += 3;
		}else if (i == counterBiceps) {
			biceps += value;
			counterBiceps += 3;
		}
		
	}

	if (back > biceps && back > chest) cout << "back";
	else if (biceps > back && biceps > chest) cout << "biceps";
	else cout << "chest";
	
}