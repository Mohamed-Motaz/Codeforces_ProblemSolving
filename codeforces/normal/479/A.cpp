#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define endl "\n"

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll a, b, c;
	cin >> a >> b >> c;

	ll x = max(a * (b + c), max((a + b) * c, a + (b * c)));
	cout << max(x, max(a * b * c, a + b + c));
}