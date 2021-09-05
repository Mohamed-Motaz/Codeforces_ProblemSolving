#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

const ll inf = 1e18, mod = 1e9 + 7;

//ll GcdRecursive(ll a, ll b);
//ll modPower(ll b, ll p);
//ll fastPower(ll b, ll p);
//ll GcdIterative(ll a, ll b);
//ll LCM(ll a, ll b);
//ll npr(ll n, ll r);
//ll ncr(ll n, ll r);
//void pre(ll n); //for npr and ncr  
//ll fact[1000001]; ll inv[1000001];
//void sieve(ll val); //for primes  
//ll primes[100007];



ll n, m;
string s;
ll counter = 0;
pair<ll, ll> startPos, endPos;
char arr[52][52];


int main() {

	MohamedMotaz;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') startPos = { i,j };
			if (arr[i][j] == 'E') endPos = { i,j };
			
		}
	}
	cin >> s;
	ll tmp[] = { 0,1,2,3 };
	do {
		
		ll first = startPos.first, second = startPos.second;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == tmp[0] + 48) {
				first++;
			}
			if (s[i] == tmp[1] + 48) {
				first--;
			}
			if (s[i] == tmp[2] + 48) {
				second++;
			}
			if (s[i] == tmp[3] + 48) {
				second--;
			}
			if (arr[first][second] == 'E') {
				counter++; break;
			}
			if (arr[first][second] == '#') break;
			if (first < 0 || first >= n || second < 0 || second >= m) break;
		}

		
	} while (next_permutation(tmp, tmp + 4));
	
	cout << counter << endl;
}

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
//
//ll LCM(ll a, ll b) {
//	return (a * b) / GcdRecursive(a, b);
//}
//ll GcdRecursive(ll a, ll b) {
//	if (b == 0) return a;
//	return GcdRecursive(b, a % b);
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