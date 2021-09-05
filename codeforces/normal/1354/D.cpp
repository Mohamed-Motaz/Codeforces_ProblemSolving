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
#define vll vector<ll>
#define vld vector<ld>
#define vi vector<int>
#define vs vector<string>
#define pll pair<ll,ll>
#define pld pair<ld, ld>
#define vpll vector<pll>
#define vpld vector<pld>
#define vc vector<char>
#define vs vector<string>
#define vp vector<point>
#define vb vector<bool>
#define mll map<ll,ll>
#define mllv map<ll, vll>
#define mcll map<char, ll>
#define msll map<string, ll>
#define mss map<string, string>
#define mcs map<char, string>
#define sll set<ll>
#define pi acos(-1)
#define point complex<ld>
using namespace std;

const ll mod = 1e9 + 7;
int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };


const ll MOD = 998244353;
//const ll mod = 1e9 + 7;
const ll N = 1e5 + 7;
const ll inf = 1e18 + 5;



//ll t, n, m, a, b, k, c = 0, d;
//ll x11, x22, y11, y22;
//string s;
int n, k;
vi v1, v2;

int ok(int a){
    int cnt = 0;
    for (auto e: v1) if (e <= a) cnt++;
    for (auto e: v2) {
        if (e < 0 && abs(e) <= cnt) cnt--;
        if (e > 0 && e <= a) cnt++;
    }
    return cnt ;
}

int main() {
    cin >> n >> k;
    v1.resize(n), v2.resize(k);
    f(i, 0, n) cin >> v1[i];
    f(i, 0, k) cin >> v2[i];

    int s = 0, e = 1e9 + 3, m, ans = -1;
    while (s <= e){
        m = (s + e) / 2;
        if (ok(m) > 0){
            ans = m;
            e = m - 1;
        }else s = m + 1;
    }
    //cout << ans << endl;
    (ans == -1) ? cout << 0: cout << ans;
}

//