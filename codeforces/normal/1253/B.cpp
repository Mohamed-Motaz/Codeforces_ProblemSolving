#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define f(a, b, c) for(ll a = b; a < c; a++)
using namespace std;
const ll mod = 1e9 + 7;



//ll fact[1000001]; ll inv[1000001];
//ll primes[100007];
//ll arr[1000007];
//ll modPower(ll b, ll p) {
//	if (p == 0)
//		return 1;
//
//	ll halfpow = modPower(b, p / 2);
//	ll toReturn = (halfpow * halfpow) % mod;
//	if (p % 2)
//		toReturn = (toReturn * b) % mod;
//
//	return toReturn;
//}
//
//ll fastPower(ll b, ll p) {
//	if (p == 0)
//		return 1;
//	ll ans = fastPower(b, p / 2);
//	ans = (ans * ans);
//	if (p % 2 != 0)
//		ans = (ans * b);
//	return ans;
//}
//ll GcdRecursive(ll a, ll b) {
//	if (b == 0) return a;
//	return GcdRecursive(b, a % b);
//}
//ll modLCM(ll a, ll b) {
//	ll val = GcdRecursive(a, b);
//	ll tmp = ((a % mod) * (b % mod)) % mod;
//	ll finalVal = ((tmp % mod) * (arr[val] % mod)) % mod;
//	return finalVal;
//
//}
//ll LCM(ll a, ll b) {
//	return (a * b) / GcdRecursive(a, b);
//}
//void move1step(ll& a, ll& b, ll q) { // a and b by reference
//	ll c = a - q * b;
//	a = b;
//	b = c;
//}
//ll GcdIterative(ll a, ll b) {
//	while (b) move1step(a, b, a / b);
//	return a;
//}
//
//void pre(ll n) {
//
//	fact[0] = 1;
//	inv[0] = 1;
//
//	for (ll i = 1; i <= n; i++) {
//		fact[i] = (i * fact[i - 1]) % mod;
//		inv[i] = modPower(fact[i], mod - 2);
//		arr[i] = modPower(i, mod - 2);
//	}
//}
//
//ll npr(ll n, ll r) {
//	return ((fact[n] * inv[n - r]) % mod);
//}
//
//ll ncr(ll n, ll r) {
//	return ((((fact[n] * inv[n - r]) % mod) * inv[r]) % mod);
//}
//
//void sieve(ll val) {
//	memset(primes, 1, sizeof primes);
//	primes[0] = primes[1] = false;
//	for (int i = 2; i <= val; i++) {
//		if (primes[i]) {
//			for (int j = i * i; j <= val; j += i) {
//				primes[j] = 0;
//			}
//		}
//	}
//
//}


const ll N = 1e5 + 7;

bool checkMap(map<ll,ll> mp) {
	for (auto elem : mp) {
		if (elem.second != mp[-elem.first] ) return false;
		if (elem.second > 1) return false;
	}
	return true;
}

ll current[1000007] = {};

int main() {

	MohamedMotaz;
	
	ll x; cin >> x;
	
	vector<ll> sol, tmp;
	
	//2 present, 1 left, 0 nothing
	ll val = 0;
	for (int i = 0; i < x; i++) {
		ll v; cin >> v;
		
		tmp.push_back(abs(v));

		if (v > 0) { //person came
			if (current[abs(v)] != 0) return cout << -1, 0;
			val++, current[abs(v)] = 2;
		}
		else { //person left
			if (current[abs(v)] != 2) return cout << -1, 0;
			val--, current[abs(v)] = 1;
		}
		
		if (!val) {
			sol.push_back(tmp.size());
			for (auto elem : tmp) current[elem] = 0;
			tmp.clear();
			
		}
	}

	if (sol.empty()) return cout << -1, 0;
	ll s = 0;
	for (auto elem : sol) s += elem;
	if (s != x) return cout << -1, 0;
	cout << sol.size() << endl;
	cout << sol[0] << ' ';

	for (int i = 1; i < sol.size(); i++) {
		cout << sol[i] << " ";
	}

}