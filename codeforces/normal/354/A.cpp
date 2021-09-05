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


const ll MOD = 998244353;
const ll mod = 1e9 + 7;
const ll N = 1e4 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;

ll n, l, r, ql, qr;
vll v;
ll dp[N][N][5];
                            // 2 -> beginning 0 -> left 1-> right
ll solve(ll idxL, ll idxR, ll choice){
    if (dp[idxL][idxR][choice] != -1) return dp[idxL][idxR][choice];
    if (idxL == idxR){
        //get min ans;
        ll mn = llinf;
        if (choice == 0){
            //left
            mn = min({mn, v[idxL] * l + ql, v[idxR] * r});
        }else if (choice == 1){
            //right
            mn = min({mn, v[idxR] * r + qr, v[idxL] * l});
        }else{
            //beginning
            mn = min({mn, v[idxR] * r, v[idxL] * l});
        }
        return mn;

    }else{
        //get min ans;
        ll mn = llinf;
        if (choice == 2){
            mn = min({mn,
                         v[idxL] * l + solve(idxL + 1, idxR, 0),
                         v[idxR] * r + solve(idxL, idxR - 1, 1)});
        }
        if (choice == 0){
            //left
            mn = min({mn,
                      v[idxL] * l + ql + solve(idxL + 1, idxR, 0),
                      v[idxR] * r + solve(idxL, idxR - 1, 1)});
        }
        if (choice == 1){
            //right
            mn = min({mn,
                      v[idxL] * l + solve(idxL + 1, idxR, 0),
                      v[idxR] * r + qr + solve(idxL, idxR - 1, 1)});
        }
        return dp[idxL][idxR][choice] = mn;
    }
}

int main() {
    MohamedMotaz
    memset(dp, -1, sizeof(dp));
    cin >> n >> l >> r >> ql >> qr;
    v.resize(n);
    f(i,0,n) cin >> v[i];
    ll ans = solve(0, n - 1, 2);
    cout << ans;

}