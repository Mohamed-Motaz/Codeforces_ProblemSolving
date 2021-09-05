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


const ll mod = 1e9 + 7;
int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };


const ll MOD = 998244353;
//const ll mod = 1e9 + 7;
const ll N = 1e7 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;

int n, m, tempMx = 0, tempCounter = 0;
vii v;

bool ok(int mid){
    mid++;
    tempCounter = mid;
    tempMx = 0;
    vii temp(n);
    f(i, 0, n){
        temp[i] = v[i] + (i + 1) * mid;
    }
    sort(all(temp));
    f(i, 0, mid){
        tempMx += temp[i];
    }
    //cout << "mid: " << mid << ", tempCounter: " << tempCounter << ", tempMx "<< tempMx << endl;
    return tempMx <= m;
}

int main() {
    MohamedMotaz
    cin >> n >> m;
    v.resize(n);
    f(i, 0, n) cin >> v[i];

    int s = 0, e = n - 1, mid, mx = 0, counter = 0;

    while (s <= e){
        mid = (s + e) / 2;
        if (ok(mid)){
            //cout << "in" << endl;
            if (tempCounter > counter){
                counter = tempCounter;
                mx = tempMx;
            }else if (tempCounter == counter && tempMx < mx){
                mx = tempMx;
            }
            s = mid + 1;
        }else e = mid - 1;
    }

    cout << counter << " " << mx;

}