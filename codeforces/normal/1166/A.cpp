#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#include <string>

#define ll long long
#define endl '\n'

using namespace std;

ll factorial[100000];
ll inverse[100000];
ll mod;


ll pre(){
	factorial[0] = factorial[1] = 1;
	inverse[0] = 1;
	
	for (int i = 1; i < 100000; i++){
		factorial[i] = i * factorial[i - 1];
		inverse[i] = pow(i, mod - 2);
	}
	return 0;
}
		

ll mySum(ll val){

	return (val * (val - 1) / 2);
}

int main(){
	//pre();
	
	ll x; cin >> x;
	map<char, ll> mp;
	for (int i = 0; i < x; i++){
		string s; cin >> s;
		mp[s[0]]++;
	}

	ll sum = 0;
	
	for (auto elem : mp){
		
		//cout << mySum(ceil(elem.second / 2.0)) << " " << mySum(floor(elem.second / 2.0)) << endl;
		sum += mySum(ceil(elem.second / 2.0)) + mySum(floor(elem.second / 2.0));
	}

	cout << sum << endl;
}