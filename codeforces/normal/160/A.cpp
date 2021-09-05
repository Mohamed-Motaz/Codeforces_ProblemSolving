#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x, sum = 0;
	cin >> x;
	vector<ll> nums;
	while (x--) {
		ll val; cin >> val;
		sum += val;
		nums.push_back(val);
	}
	sort(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	/*for (auto elem : nums) {
		cout << elem << endl;
	}*/
	ll temp = 0, counter = 0;
	for (int i = 0; i < nums.size(); i++) {
		temp += nums[i];
		counter++;
		if (temp >= sum / 2 + 1) break;
	}
	//cout << "temp is now: " << temp << endl;
	cout << counter;
}