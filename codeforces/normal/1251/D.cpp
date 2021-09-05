#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define f(a, b, c) for(int a = b; a < c; a++)
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



ll t, n, s;
vector<pair<ll, ll>> vals;

bool canDo(ll mid) {
    ll sum = 0, cnt = 0;
    vector<ll> medians;
    f(i, 0, n) {
        if (vals[i].second < mid) {
            sum += vals[i].first;
        }
        else if (vals[i].first >= mid) {
            sum += vals[i].first; cnt++;
        }
        else {
            medians.push_back(vals[i].first);
        }

    }
    ll toBeFilled = max((ll)0,(n + 1) / 2 - cnt); //could be negative
    if (medians.size() < toBeFilled) return false;

    f(i, 0, medians.size()) {
        if (i < medians.size() - toBeFilled)
            sum += medians[i];
        else sum += mid;
    }
    return sum <= s;

}

int main()
{
    MohamedMotaz;
    
    cin >> t;
    while (t--) {
        vals.clear();
        cin >> n >> s;
            
        f(i, 0, n) {
            ll a, b; cin >> a >> b;
            vals.push_back({ a,b });
        }
        sort(vals.begin(), vals.end());
        ll s = 1, e = 1e9 + 7, m;
        ll ans = 1;
       
        while (s <= e) {
            m = (s + e) / 2;
            if (canDo(m)) {
                s = m + 1;
                ans = m;
            }
            else e = m - 1;
        }

        cout <<ans << endl;
    
    }

}