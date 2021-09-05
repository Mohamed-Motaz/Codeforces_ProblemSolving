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


const ll N = 3e9 + 7;


ll n;
ll doc, vol, conf;

vector<ll> office, hall, confidence;
vector<ll> sol;
vector<bool> alive;

int main() {

	MohamedMotaz;
	
	cin >> n;

	office.resize(n), hall.resize(n), confidence.resize(n), alive.resize(n);
	for (auto e : alive) e = true;
	f(i, 0, n) {
		cin >> office[i] >> hall[i] >> confidence[i];
	}
	
	f(i, 0, n) {
		if (!alive[i]) continue;
		sol.push_back(i );

		vector<ll> leave;
		ll scream = office[i];
		f(j, i + 1, n) {
			if (!alive[j]) continue;

			confidence[j] -= scream;
			scream--;
			if (confidence[j] < 0) {
				leave.push_back(j); alive[j] = false;
			}
			if (scream == 0) break;
		}
		ll index = 0;
		while (!leave.empty()) {
			ll boyPos = leave.back(); //cant be front as must pop back not pop front
			ll scream2 = hall[boyPos];
			leave.pop_back();
			f(j, boyPos + 1, n) {
				if (!alive[j]) continue;
				confidence[j] -= scream2;

				if (confidence[j] < 0) {
					alive[j] = false; leave.push_back(j);
				}
			}


		}

	}

	cout << sol.size() << endl;
	for (auto e : sol) cout << e + 1 << " ";
	
	
}