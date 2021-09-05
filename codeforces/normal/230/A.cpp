
#include <bits/stdc++.h>

using namespace std;



int main() {

	long long x, mainStrength, dragonStrength, bonusForKillingDragon;
	vector<pair<long long, long long>> dragonDetails;
	bool win = true;
	cin >> mainStrength >> x;

	for (int i = 0; i < x; i++) {
		cin >> dragonStrength >> bonusForKillingDragon;
		pair<long long, long long> temp;
		temp.first = dragonStrength;
		temp.second = bonusForKillingDragon;
		dragonDetails.push_back(temp);
		
	}

	sort(dragonDetails.begin(), dragonDetails.end());

	for (int i = 0; i < x; i++) {
		if (mainStrength > dragonDetails[i].first) mainStrength += dragonDetails[i].second;
		else {
			win = false;
		}
	}
	if (win) cout << "YES";
	else cout << "NO";
}