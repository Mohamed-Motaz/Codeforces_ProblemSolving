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
const ll N = 2e5 + 7;
const ll inf = 1e9 + 5;





ll n, k;
ll dp[2070][2070][4];

int main() {

    cin >> n >> k;
    dp[1][1][0] = 1;
    dp[1][1][1] = 1;
    dp[1][2][2] = 1;
    dp[1][2][3] = 1;
    f(i,2, n + 1){

        f(j, 1, k + 1){

            // white - white
            dp[i][j + 0][0] = (dp[i][j + 0][0] + dp[i - 1][j][0]) % MOD;
            dp[i][j + 1][0] = (dp[i][j + 1][0] + dp[i - 1][j][1]) % MOD;
            dp[i][j + 0][0] = (dp[i][j + 0][0] + dp[i - 1][j][2]) % MOD;
            dp[i][j + 0][0] = (dp[i][j + 0][0] + dp[i - 1][j][3]) % MOD;
            //black - black
            dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i - 1][j][0]) % MOD;
            dp[i][j + 0][1] = (dp[i][j + 0][1] + dp[i - 1][j][1]) % MOD;
            dp[i][j + 0][1] = (dp[i][j + 0][1] + dp[i - 1][j][2]) % MOD;
            dp[i][j + 0][1] = (dp[i][j + 0][1] + dp[i - 1][j][3]) % MOD;
            //white - black
            dp[i][j + 1][2] = (dp[i][j + 1][2] + dp[i - 1][j][0]) % MOD;
            dp[i][j + 1][2] = (dp[i][j + 1][2] + dp[i - 1][j][1]) % MOD;
            dp[i][j + 0][2] = (dp[i][j + 0][2] + dp[i - 1][j][2]) % MOD;
            dp[i][j + 2][2] = (dp[i][j + 2][2] + dp[i - 1][j][3]) % MOD;
            //black - white
            dp[i][j + 1][3] = (dp[i][j + 1][3] + dp[i - 1][j][0]) % MOD;
            dp[i][j + 1][3] = (dp[i][j + 1][3] + dp[i - 1][j][1]) % MOD;
            dp[i][j + 2][3] = (dp[i][j + 2][3] + dp[i - 1][j][2]) % MOD;
            dp[i][j + 0][3] = (dp[i][j + 0][3] + dp[i - 1][j][3]) % MOD;
        }
    }
    cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) % MOD << endl;
}