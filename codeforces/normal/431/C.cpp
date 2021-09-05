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
#include <complex>

#define ll long long
#define ld long double
#define debug(x) cerr << (#x) << " " << (x) <<" "<< endl
#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define f(a, b, c) for(ll a = b; a < c; a++)
#define fr(a, b, c) for(int a = b; a >= c; a--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define vll vector<ll>
#define vld vector<ld>
#define vii vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define pld pair<ld, ld>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpld vector<pld>
#define vc vector<char>
#define vs vector<string>
#define vp vector<point>
#define vb vector<bool>
#define mll map<ll,ll>
#define mii map<int, int>
#define mllv map<ll, vll>
#define mcll map<char, ll>
#define mci map<char, int>
#define msll map<string, ll>
#define mss map<string, string>
#define mcs map<char, string>
#define sll set<ll>
#define pi acos(-1)
#define point complex<ld>
using namespace std;


int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };

ll gcd(ll a, ll b) {
    if (!b)return a;
    return gcd(b, a % b);
}
ll lcm (ll a, ll b) {
    return a * b / gcd(a, b);
}

const ll MOD = 998244353;
const ll mod = 1e9 + 7;
const ll N = 1e3 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;

ll n, k, d;
ll dp[107][3];

ll solve(ll sum, bool done){
    if (sum > n) return 0;
    if (sum == n) return done;
    if (dp[sum][done] != -1) return dp[sum][done];
    ll ans = 0;
    f(i, 1, k + 1) ans = ((ans % mod ) + (solve(sum + i, done || (i >= d)) % mod)) % mod;
    return dp[sum][done] = ans ;
}

int main() {
    MohamedMotaz
    memset(dp, -1, sizeof(dp));
    cin >> n >> k >> d;
    cout << solve(0, false);

}