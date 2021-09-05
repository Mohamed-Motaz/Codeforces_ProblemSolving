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
const int N = 2e5 + 7;
int n;
struct money{
    ll toPay;
    ll ones, fives, tens, twenties, fifties;
    ll sum;
    ll dif;
    int idx;
};

vector<money> v;
bool comp(money a, money b){
    if (a.dif != b.dif)
        return a.dif < b.dif;

    return a.toPay < b.toPay;
}

bool check(){
    map<int, int> mp;
    mp[1] = 0;
    mp[5] = 0;
    mp[10] = 0;
    mp[20] = 0;
    mp[50] = 0;
    for (int i = 0; i < n; i++){
        ll k = v[i].toPay;
        int one = v[i].ones, five = v[i].fives,
                ten = v[i].tens, twenty = v[i].twenties, fifty = v[i].fifties;
        mp[1] += one;
        mp[5] += five;
        mp[10] += ten;
        mp[20] += twenty;
        mp[50] += fifty;
        ll sum = one + five * 5 + ten * 10 + twenty * 20 + fifty * 50;
        if (sum >= k){
            k = sum - k;
            while (k >= 50){
                mp[50]--;
                if (mp[50] < 0)
                    return false;
                k -= 50;
            }
            while (k >= 20){
                mp[20]--;
                if (mp[20] < 0)
                    return false;
                k -= 20;
            }
            while (k >= 10){
                mp[10]--;
                if (mp[10] < 0)
                    return false;
                k -= 10;
            }
            while (k >= 5){
                mp[5]--;
                if (mp[5] < 0)
                    return false;
                k -= 5;
            }
            while (k >= 1){
                mp[1]--;
                if (mp[1] < 0)
                    return false;
                k -= 1;
            }
        }

    }
    return true;
}

int main() {
    MohamedMotaz;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n;i ++){
        cin >> v[i].toPay >> v[i].ones >> v[i].fives >> v[i].tens >> v[i].twenties >> v[i].fifties;
        v[i].idx = i;
        v[i].sum = v[i].ones * 1 + v[i].fives * 5 + v[i].tens * 10
                   + v[i].twenties * 20 + v[i].fifties * 50;
        v[i].dif = v[i].sum - v[i].toPay;
    }

    sort(all(v), comp);
    if (!check())
        return cout << -1, 0;

    for (auto e: v){
        cout << e.idx + 1 <<  " ";
    }

}