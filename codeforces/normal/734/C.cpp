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
#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define f(a, b, c) for(int a = b; a < c; a++)
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

ll GcdRecursive(ll a, ll b) {
	if (b == 0) return a;
	return GcdRecursive(b, a % b);
}

const ll mod = 1e9 + 7;
int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };


const ll MOD = 998244353;
//const ll mod = 1e9 + 7;
const ll N = 2e3 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;

ll t, n, m, a, b, k, c = 0, d, x , y, s;
ll x11, x22, y11, y22;
vpll ff, ss;

int main() {
    MohamedMotaz
    cin >> n >> m >> k >> x >> s;
    ff.resize(m), ss.resize(k);
    ll mn = n * x;
    f(i, 0, m) cin >> ff[i].first;
    f(i, 0, m) cin >> ff[i].second, (ff[i].second <= s) ? mn = min(mn * 1LL, n * ff[i].first) : 0;
    f(i, 0, k) cin >> ss[i].first;
    f(i, 0, k) cin >> ss[i].second, (ss[i].second <= s) ? mn = min(mn * 1LL, (n - ss[i].first) * x) : 0;

    f(i, 0, m){
        int start = 0, end = k - 1, mid;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (ff[i].second + ss[mid].second <= s)
            {
                mn = min(mn * 1ll, (n - ss[mid].first) * ff[i].first);
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
    }

    cout << mn;
}