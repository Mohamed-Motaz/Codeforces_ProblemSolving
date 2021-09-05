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
#define vpll vector<pair<ll,ll>>
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
const ll N = 3e5 + 7;
const ll inf = 1e18 + 5;


ll x1,y11,x2,y2,x3,y3;
ll dx[] = {1,0,-1,0};
ll dy[] = {0,-1,0,1};
ld s1, s2, s3;


bool checkIfRight(ld s1, ld s2, ld s3) {return (s1 + s2 == s3 || s1 + s3 == s2 || s2 + s3 == s1);}


void createSides(ld x1,ld y11,ld x2,ld y2,ld x3,ld y3, ld& s1, ld& s2, ld& s3){
    s1 = pow(x1 - x2,2) + pow(y11 - y2, 2);
    s2 = pow(x1 - x3,2) + pow(y11 - y3, 2);
    s3 = pow(x3 - x2,2) + pow(y3 - y2, 2);
}

bool changeOnePoint(){
    f(i,0,4){
        x1 += dx[i];
        y11 += dy[i];
        ld s1 = 0, s2 = 0, s3 = 0;
        createSides(x1, y11, x2, y2, x3, y3, s1, s2, s3);
        if (checkIfRight(s1, s2, s3)) return true;
        x1 -= dx[i], y11 -= dy[i];
    }

    f(i,0,4){
        x2 += dx[i];
        y2 += dy[i];
        ld s1 = 0, s2 = 0, s3 = 0;
        createSides(x1, y11, x2, y2, x3, y3, s1, s2, s3);
        if (checkIfRight(s1, s2, s3)) return true;
        x2 -= dx[i], y2 -= dy[i];
    }

    f(i,0,4){
        x3 += dx[i];
        y3 += dy[i];
        ld s1 = 0, s2 = 0, s3 = 0;
        createSides(x1, y11, x2, y2, x3, y3, s1, s2, s3);
        if (checkIfRight(s1, s2, s3)) return true;
        x3 -= dx[i], y3 -= dy[i];
    }

    return false;

}

int main() {
    MohamedMotaz

    cin >> x1 >> y11 >> x2 >> y2 >> x3 >> y3;

    s1 = pow(x1 - x2,2) + pow(y11 - y2, 2);
    s2 = pow(x1 - x3,2) + pow(y11 - y3, 2);
    s3 = pow(x3 - x2,2) + pow(y3 - y2, 2);

    if (checkIfRight(s1,s2,s3)) return cout << "RIGHT", 0;

    if (changeOnePoint()) return cout << "ALMOST", 0;
    return cout << "NEITHER", 0;

}