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

ll solve1(    map<ll, set<ll>> mp){
    vector<ll> vals;
    for (auto e: mp){
        vals.push_back(e.first);
        //sort(all(e.second));
    }
//    for (auto e: v){
//        cout << e.first << " " << e.second << endl;
//    }
    ll ctr = 0;
    for (int i = 0; i < vals.size() - 1; i++){
        sll s1 = mp[vals[i]], s2 = mp[vals[i + 1]];
        //debug2(s1.size(), s1.size());
        ll curMx = *s1.rbegin();
        ll curMn = *s1.begin();

        auto it1 = --s2.end();
        auto it2 = s2.begin();

        ll nextMx = *it1;
        ll nextMn = *it2;

        ll ans1 = abs(curMx - nextMx);
        ll ans2 = abs(curMx - nextMn);
        ll ans3 = abs(curMn - nextMx);
        ll ans4 = abs(curMn - nextMn);

        if (ans1 == max({ans1, ans2, ans3, ans4})){
            ctr += ans1;
            if (mp[vals[i + 1]].size() > 1)
                s2.erase(it1),
                        mp[vals[i + 1]] = s2;
        }else if (ans2 == max({ans1, ans2, ans3, ans4})){
            ctr += ans2;
            if (mp[vals[i + 1]].size() > 1)
                s2.erase(it2),
                        mp[vals[i + 1]] = s2;
        }else if (ans3 == max({ans1, ans2, ans3, ans4})){
            ctr += ans3;
            if (mp[vals[i + 1]].size() > 1){
                s2.erase(it1),
                        mp[vals[i + 1]] = s2;
            }
        }else if (ans4 == max({ans1, ans2, ans3, ans4})){
            ctr += ans4;
            if (mp[vals[i + 1]].size() > 1)
                s2.erase(it2),
                        mp[vals[i + 1]] = s2;
        }

    }
    return ctr;
}

ll solve2(    map<ll, set<ll>> mp){
    vector<ll> vals;
    for (auto e: mp){
        vals.push_back(e.first);
        //sort(all(e.second));
    }
//    for (auto e: v){
//        cout << e.first << " " << e.second << endl;
//    }
    ll ctr = 0;
    for (int i = vals.size() - 1; i >= 1; i--){
        sll s1 = mp[vals[i]], s2 = mp[vals[i - 1]];
        //debug2(s1.size(), s1.size());
        ll curMx = *s1.rbegin();
        ll curMn = *s1.begin();

        auto it1 = --s2.end();
        auto it2 = s2.begin();

        ll nextMx = *it1;
        ll nextMn = *it2;

        ll ans1 = abs(curMx - nextMx);
        ll ans2 = abs(curMx - nextMn);
        ll ans3 = abs(curMn - nextMx);
        ll ans4 = abs(curMn - nextMn);

        if (ans1 == max({ans1, ans2, ans3, ans4})){
            ctr += ans1;
            if (mp[vals[i - 1]].size() > 1)
                s2.erase(it1),
                        mp[vals[i - 1]] = s2;
        }else if (ans2 == max({ans1, ans2, ans3, ans4})){
            ctr += ans2;
            if (mp[vals[i - 1]].size() > 1)
                s2.erase(it2),
                        mp[vals[i - 1]] = s2;
        }else if (ans3 == max({ans1, ans2, ans3, ans4})){
            ctr += ans3;
            if (mp[vals[i - 1]].size() > 1){
                s2.erase(it1),
                        mp[vals[i - 1]] = s2;
            }
        }else if (ans4 == max({ans1, ans2, ans3, ans4})){
            ctr += ans4;
            if (mp[vals[i - 1]].size() > 1)
                s2.erase(it2),
                        mp[vals[i - 1]] = s2;
        }

    }
    return ctr;
}

int main() {
    MohamedMotaz;
    cin >> n;
    vpll v(n);
    map<ll, set<ll>> mp;
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        mp[v[i].first].insert(v[i].second);
    }

    cout << max(solve1(mp), solve2(mp));

}


//5
//0 2
//1 3
//1 5
//1 20
//2 3

//20

//5
//0 2
//1 3
//1 0
//1 20
//2 3