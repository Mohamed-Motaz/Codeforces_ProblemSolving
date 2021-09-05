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

//#include <ext/pb_ds/assoc_container.hpp>   //ordered_set
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ld long double
#define ull unsigned long long

#define debug1(x) cout << (#x) << " " << (x) <<" "<< endl
#define debug2(x,y) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< endl
#define debug3(x,y,z) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << endl
#define debug4(x,y,z, a) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << " "<< (#a) << " " << (a) << endl

#define trace1(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl


#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define readwrite freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define vll vector<ll>
#define vii vector<int>

using namespace std;
//using namespace __gnu_pbds;


int dirX[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dirY[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
//const ll mod = 998244353;
const ll mod = 1e9 + 7;
const int N = 2e5 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;
const int infClr = 0x3f3f3f3f;

ll t;
ll n, k, m, a, b, r, d, x, y, q, z, f, l, p, g, h, c, T;

int main() {
    MohamedMotaz;

    cin >> t;
    while (t--){
        cin >> n >> k;
        vll v(n), tmpVec(n);
        for (int i = 0; i < n; i++){
            cin >> v[i]; tmpVec[i] = v[i];
        }
        int last = intinf;
        vector<int> pos(1e7, -1);
        int tmp = k;
        for (int i = 1 ; i <= tmp; i++){
            int idx = 0, prev = intinf;
            while (idx < tmpVec.size()){
                if (tmpVec[idx] <= prev) {
                    prev = tmpVec[idx];
                    idx++;
                    continue;
                }
                pos[i] = idx;
                tmpVec[idx - 1]++;
                break;
            }
            if (idx == tmpVec.size()){
                last = i;
                break;
            }
        }
        if (k >= last){
            cout << -1 << endl;
            continue;
        }
        cout << pos[k] << endl;

    }


}