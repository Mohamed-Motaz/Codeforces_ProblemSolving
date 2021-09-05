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


const ll mod = 1e9 + 7;
int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };


const ll MOD = 998244353;
//const ll mod = 1e9 + 7;
const ll N = 5e5 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;

int n;

int main() {
    MohamedMotaz
    cin >> n;
    vpii v(n);
    f(i, 0, n) cin >> v[i].first, v[i].second = i + 1;
    sort(all(v));
    vpii first, second;
    f(i, 0, n){
        if (i % 2) second.push_back(v[i]);
        else first.push_back(v[i]);
    }
    cout << first.size() << endl;
    for (auto e: first) cout << e.second << " "; cout << endl;
    cout << second.size() << endl;
    for (auto e: second) cout << e.second << " "; cout << endl;
}