#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <set>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double>
#define all(a) a.begin(), a.end()
#define pi acos(-1)
#define mod 998244353
using namespace std;
int n, t;
const ll N = 1e5 + 3;
vector<ll> odd;


int main() {
    HS;
    cin>>n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<ll> cumSum(n);
    cumSum[0] = v[0];
    for (int i = 1; i < n ; i++){
        cumSum[i] = cumSum[i - 1] + v[i];
    }
    //for(auto e: cumSum) cout << e << " "; cout << endl;
    ll sum = v[0] * (cumSum[n - 1] - v[0]);
    //cout << sum << endl;
    for(int i = 1; i < n; i++){
        sum += v[i] * (cumSum[n - 1] - cumSum[i]);
    }
    cout << sum << endl;


}