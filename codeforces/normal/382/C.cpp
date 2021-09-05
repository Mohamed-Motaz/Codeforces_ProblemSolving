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


int main() {
    MohamedMotaz
    cin >> n;
    if (n == 1) return cout << -1, 0;
    vll v(n);
    f(i, 0, n) cin >> v[i];
    sort(all(v));
    mll mp;
    f(i, 0, n - 1) mp[v[i + 1] - v[i]]++;
    ll diff = v[1] - v[0];
    if (mp.size() == 1 && diff == 0){
        return cout << 1 << endl << v[0] << endl, 0;
    }
    if (mp.size() == 1 && n > 2) return cout << 2 << endl << v[0] - diff << " " << v[n - 1] + diff, 0;

    if (mp.size() == 1 && n == 2 && diff % 2 == 0){
        if (diff == 0){
            return cout << 1 << endl << v[0] << endl, 0;
        }
        cout << 3 << endl;
        cout << v[0] - diff << ' ' << ( v[0] + v[1] )/ 2 << " " << v[n - 1] + diff << endl; return 0;
    }
    if (mp.size() == 1 && n == 2 && diff % 2){
        cout << 2 << endl;
        cout << v[0] - diff << ' ' << v[n - 1] + diff << endl; return 0 ;
    }

    if (mp.size() > 2) return cout << 0, 0;

    if (mp.size() == 2){
        ll mnDiff = inf, mxDiff = -inf;
        for (auto e: mp) mnDiff = min(mnDiff, e.first), mxDiff = max(mxDiff, e.first);
        for (auto e: mp){
            if (e.first == mxDiff) if (e.second > 1) return cout << 0, 0;
        }
        if (mxDiff == 2 * mnDiff){
            cout << 1 << endl;
            f(i, 0, n - 1){
                if (v[i + 1] - v[i] == mxDiff) return cout << (v[i + 1] + v[i]) / 2, 0;
            }

        }else return cout << 0,0;

    }

}