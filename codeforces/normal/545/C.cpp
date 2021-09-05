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



ll t, n, m, a, b, k, c = 0, d;
ll x11, x22, y11, y22;



    ll dp[N][3]; //leave, left, right

    int main() {
        MohamedMotaz
        cin >> n;
        vpll v(n);
        f(i, 0, n) cin >> v[i].first >> v[i].second;

        dp[0][0] = 0;
        dp[0][1] = 1;

        dp[0][2] = (v[0].first + v[0].second < v[1].first) ? 1 : 0;

        f(i, 1, n){
            dp[i][0] = max({dp[i - 1][0],dp[i - 1][1], dp[i - 1][2]});
            dp[i][1] = dp[i][0];
            dp[i][2] = dp[i][0];
            if (v[i].first - v[i].second > v[i - 1].first ){
                //can take left if leave or already left
                dp[i][1] = 1 + max({dp[i - 1][1], dp[i - 1][0]});
            }if (v[i].first - v[i].second >  v[i - 1].first + v[i - 1].second){
                //can take left if right or not take
                dp[i][1] = max({dp[i - 1][2] + 1, 1 + dp[i - 1][1], 1 + dp[i - 1][0]});
            }
            if (i == n - 1 || (i < n - 1 &&  v[i + 1].first > v[i].second + v[i].first)){
                dp[i][2]++;
            }

        }

        cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

    }