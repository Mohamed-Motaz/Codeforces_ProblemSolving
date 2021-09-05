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
#define mcii map<char, int>
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
const ll N = 1e2 + 7;
const ll llinf = INT64_MAX;
const int intinf = INT32_MAX;

ll n, l, r, ql, qr;
vll v;
string s, t;
//remove elements of a s to get t
bool elementsNeedToBeRemoved(){
    return s.size() != t.size();
}
bool wordfound(){
    int counter = 0, j = 0;
    f(i, 0, t.size()){
        bool found = false;
        for(;j < s.size(); j++){
            if (t[i] == s[j]){
                found = true;
                break;
            }
        }
        counter += found;
    }
    return counter == t.size();
}


int main() {
    MohamedMotaz
    cin >> s >> t;
    //automaton -> remove elements of a string to get t
    //array -> swap elements only
    //need tree -> no way to change s to t
    mcii ss, tt;
    for (auto e: s) ss[e]++;
    for (auto e: t) tt[e]++;
    bool needTree = false;
    for (auto e: tt){
        if (ss[e.first] < e.second) needTree = true;
    }
    if (needTree) return cout << "need tree", 0;

    bool swapNeeded = true;
    int j = 0, counter = 0;
    f(i, 0, t.size()){
        bool found = false;
        for (;j < s.size(); j++){
            if (t[i] == s[j]){
                found = true;
                j++;
                break;
            }
        }
        counter += found;
    }
    //debug(counter), debug(t.size()), debug(s.size());
    if (counter == t.size()) swapNeeded = false;
    bool removeNeeded = t.size() != s.size();
    if (removeNeeded && swapNeeded) return cout << "both", 0;
    if (swapNeeded) return cout << "array", 0;
    if (removeNeeded) return cout << "automaton", 0;





}