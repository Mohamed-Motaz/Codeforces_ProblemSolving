#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <iomanip>

#define ll long long
#define ld long double
#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define f(a, b, c) for(int a = b; a < c; a++)
#define fr(a, b, c) for(int a = b; a >= c; a--)
#define all(a) a.begin(), a.end()
#define vll vector<ll>
#define pll pair<ll,ll>
#define vi vector<int>
using namespace std;


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

const ll MOD = 998244353;
const ll mod = 1e9 + 7;
const ll N = 2e3 + 7;
const ll inf = 1e18 + 5;




ll n, t, d, p;
vector<pair<pll, pll>> v;
ll dp[107][N];
pll construct[107][N];

ll solve(ll index, ll timePassed){
        if (index >= n) return 0;
        if (dp[index][timePassed] != -1) return dp[index][timePassed];
        ll take = -1, leave = -1;

        leave = solve(index + 1, timePassed);
        if (timePassed + v[index].second.first < v[index].first.first)
            take = solve(index + 1, timePassed + v[index].second.first ) + v[index].second.second;

        if (take > leave){
            construct[index][timePassed] = {index + 1, timePassed + v[index].second.first};
        }else{
            construct[index][timePassed] = {index + 1, timePassed};
        }

        return dp[index][timePassed] = max(take, leave);
}

int main() {
    MohamedMotaz
    memset(dp, -1, sizeof(dp));
    cin >> n;
    v.resize(n);
    f(i,0,n) cin >> v[i].second.first >> v[i].first.first >> v[i].second.second, v[i].first.second = i + 1;
    sort(all(v));
    ll ans = solve(0, 0);
    cout << ans << endl;

    vll a;
    pll curr = {0,0};

    while (curr.first < n){
        if (curr.second < construct[curr.first][curr.second].second) a.push_back(v[curr.first].first.second);


        curr = construct[curr.first][curr.second];
    }

    cout << a.size() << endl;
    if (!a.size()) return 0;
    for (auto elem: a) cout << elem << " " ;

}