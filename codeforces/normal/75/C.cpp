#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

const ll inf = 2e18, mod = 1e9 + 7;

ll GcdRecursive(ll a, ll b);
ll modPower(ll b, ll p);
ll GcdIterative(ll a, ll b);
ll LCM(ll a, ll b);
ll npr(ll n, ll r);
ll ncr(ll n, ll r);
void pre(); //for npr and ncr  
ll fact[1000001]; ll inv[1000001];
ll a, b, n;
bool check(ll val) {

	while (val) {
		ll temp = val % 10;
		if (temp != a && temp != b)
			return false;
		val /= 10;
	}


	return true;
}

int main() {
	
	MohamedMotaz;
	
	ll a, b; cin >> a >> b;
	ll gcdVal = GcdRecursive(a, b);
	
	set<ll> vals;
	vals.insert(gcdVal);
	for (int i = 1; i * i <= gcdVal; i++) {

		if (gcdVal % i == 0) {
	
			vals.insert(i);
			vals.insert(gcdVal / i);
		}
	}
	ll x; cin >> x;
	while (x--) {
		ll tmp1, tmp2;
		bool found = false;
		cin >> tmp1 >> tmp2;
		set<ll>::reverse_iterator rit;
		for (rit = vals.rbegin(); rit != vals.rend(); rit++) {
			if (*rit >= tmp1 && *rit <= tmp2) {
				cout << *rit << endl;
				found = true;
				break;
			}
		}
		if (!found) cout << -1 << endl;
	}


}

ll modPower(ll b, ll p) {
	if(p == 0)
		return 1;

	ll halfpow = modPower(b, p / 2);
	ll toReturn = (halfpow * halfpow) % mod;
	if (p % 2)
		toReturn = (toReturn * b) % mod;

	return toReturn;
}

ll fastPower(ll b, ll p) {
	if (p == 0)
		return 1;
	ll ans = fastPower(b, p / 2);
	ans = (ans * ans);
	if (p % 2 != 0)
		ans = (ans * b);
	return ans;
}

ll LCM(ll a, ll b) {
	return (a * b) / GcdRecursive(a, b);
}
ll GcdRecursive(ll a,ll b) {
	if (b == 0) return a;
	return GcdRecursive(b, a % b);
}
void move1step(ll& a, ll& b, ll q) { // a and b by reference
	ll c = a - q * b;
	a = b;
	b = c;
}
ll GcdIterative(ll a, ll b) {
	while (b) move1step(a, b, a / b);
	return a;
}

void pre() {

	fact[0] = 1;
	inv[0] = 1;

	for (ll i = 1; i <= 1000000; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
		inv[i] = modPower(fact[i], mod - 2);
	}
}

ll npr(ll n, ll r) {
	return ((fact[n] * inv[n - r]) % mod);
}

ll ncr(ll n, ll r) {
	return ((((fact[n] * inv[n - r]) % mod) * inv[r]) % mod);
}