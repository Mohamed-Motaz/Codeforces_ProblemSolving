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

const ll MOD = 998244353;
const ll mod = 1e9 + 7;
const ll N = 1e7 + 7;
const ll inf = 1e18 + 5;

ll t, n, m, a, b, k;
ll vis[107] = {};

int main() {
    MohamedMotaz
    cin >> n;
    vll v(n);
    mll mp;
    f(i, 0, n) cin >> v[i], mp[v[i]]++;
    sort(all(v));
    ll ans = 0;
    f(i, 0, n){

        if (!vis[i]){
            ll bx = 0;

            f(j, i , n){
                if (v[j] >= bx && !vis[j]){
                    vis[j]++;
                    bx++;
                }

            }
            ans++;
        }
    }

    cout << ans;

}