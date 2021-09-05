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

ll getSum(ll a) {return a * (a + 1) / 2;}

int main() {
    MohamedMotaz
    cin >> n >> d;
    vll v(2 * n);
    f(i, 0, n) cin >> v[i], v[n + i] = v[i];

    ll ptr1 = 0, ptr2 = -1;
    ll mx = 0;
    ll countDays = 0;
    ll countHugs = 0;

    while (ptr2 < 2 * n - 1 ){
        ptr2++;
        countDays += v[ptr2];
        countHugs += getSum(v[ptr2]);

        while (countDays - v[ptr1] > d){
            countDays -= v[ptr1];
            countHugs -= getSum(v[ptr1]);
            ptr1++;
        }
        //how many extra days do I have?
        ll diff = max(countDays - d, 0LL);
        mx = max(mx, countHugs - getSum(diff));
    }

    cout << mx;

}