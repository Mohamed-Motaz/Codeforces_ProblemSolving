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
const ll LLinf = 1e18 + 5;
const int INTinf = 1e8 + 7;

ll t, n, m, a, b, k, c = 0, d, x , y;
ll x11, x22, y11, y22;




int main() {
    MohamedMotaz
    cin >> t;
    while (t--){
        cin >> n >> m;
        vll v(n);
        ll l = -1, r = -1, s = 0;

        f(i, 0, n) cin >> v[i], s += v[i];

        if (s % m ){
            cout << n << endl;
            continue;
        }

        ll cnt = n;
        ll f1 = 0, s1 = n - 1;
        while (true){
            if (s % m){
                cout << cnt << endl;
                break;
            }
            if ((s - v[f1]) % m){
                cout << cnt - 1 << endl;
                break;
            }
            else if ((s - v[s1]) % m){
                cout << cnt - 1 << endl;
                break;
            }else f1++, s1--;
            cnt--;
            if (cnt <= 0){
                cout << -1 << endl;
                break;
            }
        }


    }
}