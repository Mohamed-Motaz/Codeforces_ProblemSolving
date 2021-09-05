#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll x; 
	cin >> x;

	ll evenNo = x / 2;
	ll oddNo = ceil(x / 2.0);

	cout << evenNo * (evenNo + 1) - oddNo * oddNo;
}