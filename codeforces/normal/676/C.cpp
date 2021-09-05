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

int n, k;
//1 is a, 0 is b
vpii segments;
int dp1[N];
int solve(int counter, int idx){
    if (dp1[counter] != -1) return dp1[counter];
    if (counter <= 0 || idx >= segments.size()) return 0;
    int ans = 0;

    //take
    if (idx + 1 < n && counter >= segments[idx + 1].first){
        ans = max(ans, (idx + 2 < n) ? segments[idx + 2].first : 0 + segments[idx + 1].first + segments[idx].first + solve(counter - segments[idx + 1].first, idx + 2));
    }
    if (idx + 1 < n && counter < segments[idx + 1].first){
        ans = max(ans, segments[idx].first + segments[idx + 1].first - counter + solve(0, idx + 2));
    }
    //leave
    ans = max(ans, solve(counter, idx + 1));

    return dp1[counter] = ans;
}

int main() {
    MohamedMotaz


    cin >> n >> k;
    string s; cin >> s;
    clr(dp1, -1);
    f(i, 0, s.size()){
        int counter = 0, idx = i;
        if (s[i] == 'a'){
            while (idx < n && s[idx] == 'a') counter++, idx++;
            segments.push_back({idx - i, 1});

        }else{
            while (idx < n && s[idx] == 'b') counter++, idx++;
            segments.push_back({idx - i, 0});
        }
        i = idx - 1;
    }

    if (k == 0){
        int mx = 0;
        for (auto e: segments) mx = max(mx, e.first);
        return cout << mx, 0;
    }

    cout << solve(k, 0);



}