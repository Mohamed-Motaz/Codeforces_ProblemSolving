//
#include <iostream>
#include <stdio.h>
#include <functional>
#include <string>
#include <cstring>
#include <cstdio>
#include <numeric>
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
#include <unordered_set>
#include <assert.h>
#include <sstream>


#define ll long long
#define ld long double

#define debug1(x) cout << (#x) << " " << (x) <<" "<< endl
#define debug2(x,y) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< endl
#define debug3(x,y,z) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << endl
#define debug4(x,y,z, a) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << " "<< (#a) << " " << (a) << endl

#define trace1(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl

#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define readwrite freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define clr(x, y) memset(x, y, sizeof(x));
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
#define sz(x) (ll)x.size()
#define cinvec(v) f(i, 0, v.size()) cin >> v[i]
#define coutvec(v) for (auto e: v) cout << e << " "; cout << endl;
#define printvec(v) for (auto e: v) cout << e << " "; cout << endl;
#define pi acos(-1)
#define point complex<ld>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e3 + 7;

struct node{
    ll x, y, z;
    ll mnSum;
    ll mxSum;
    int idx;
};

bool comp(node a, node b){
    return a.mnSum <= b.mnSum;
}

int main() {
    MohamedMotaz;
    int n;
    cin >> n;
    vector<node> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].x >> v[i].y >> v[i].z;
        vector<ll> vv = {v[i].x, v[i].y, v[i].z};
        sort(all(vv));
        v[i].mnSum = (ll)vv[0] + (ll)vv[1];
        v[i].mxSum = (ll)vv[0] + (ll)vv[1] + (ll)vv[2]- 2;
        v[i].idx = i;
    }
    //1 2 5
    //6
    sort(all(v), comp);
    vector<int> sol(n, 0);
    for (int i = 0; i < n; i++){
//        debug1(i);
//        debug4(v[i].x, v[i].y, v[i].z, v[i].mnSum);

        int s = 0, e = n - 1, m;
        int idx = -1;
        while (s <= e){
            m = (s + e) / 2;
            if (v[m].mnSum <= v[i].mxSum){
//                debug4(v[m].x, v[m].y, v[m].z, v[m].mnSum);
                s = m + 1;
                idx = m;
            } else
                e = m - 1;
        }
        idx++;
        //if i can defeat myself, dec idx
        if (v[i].mnSum <= v[i].mxSum)
            idx--;

        sol[v[i].idx] = idx;
    }

    for (int i = 0; i < n; i++)
        cout << sol[i] << " ";


}