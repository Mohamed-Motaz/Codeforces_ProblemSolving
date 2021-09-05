#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <numeric>
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
#define debug1(x) cerr << (#x) << " " << (x) <<" "<< endl
#define debug2(x, y) cerr << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< endl

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
#define mcii map<char, int>
#define msll map<string, ll>
#define mss map<string, string>
#define mcs map<char, string>
#define sll set<ll>
#define pi acos(-1)
#define point complex<ld>
#define clr(a, b) memset(a, b, sizeof(a))
using namespace std;


int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };


const ll MOD = 998244353;
const ll mod = 1e9 + 7;
const ll N = 1e5 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;

int n;
vii v;
map<pair<pii, int>, int> dp;
int solve(int idx, bool changeDone, int prev){
    if (idx == n ) return 0;
    if (dp[{{idx, changeDone}, prev}] ) return dp[{{idx, changeDone}, prev}];
    int ans = 0;
    if (!changeDone){
        if (v[idx] > prev) ans = max({ans, 1 + solve(idx + 1, true, prev + 1), 1 + solve(idx + 1, changeDone, v[idx]) });
        else ans = max(ans, 1 + solve(idx + 1, true, prev + 1));
    }
    else if (v[idx] > prev) ans = max(ans, 1 + solve(idx + 1, changeDone, v[idx]));

    return dp[{{idx, changeDone}, prev}] = ans;

}

int main() {
    MohamedMotaz
    cin >> n;
    v.resize(n);
    f(i, 0, n)cin >> v[i];
    int mx = 0;
    f(i, 0, n) mx = max(mx, solve(i, false, -1));
    cout << mx;






}