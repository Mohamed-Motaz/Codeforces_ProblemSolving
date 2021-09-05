#include "bits/stdc++.h"
//#define int ll
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
const int64_t INF = (int64_t)(2e18);
const int inf = (int)(1e9 + 7);
const int maxn = 500 * 1000 + 100;
chrono::time_point<chrono::steady_clock> cl;
double current_time() { return (double)(chrono::steady_clock::now() - cl).count() / 1e9; }
//------------------------------------------//
dxfbf

void solve(){
    int n, k; 
    cin >> n >> k;
    string a,b;
    cin >> a >> b;
    //cout << "---" << endl;
    map<char, int> ma, mb;
    for (auto& it : a) ma[it]++;
    for (auto& it : b) mb[it]++;
    for (char c = 'a'; c <= 'z'; ++c){
        //cout << ma[c] << " " << mb[c] << endl;
        if (ma[c] < mb[c]){
            cout << "No" << endl;
            return;
        }
        ma[c+1] += (ma[c] - mb[c]) / k * k;
        ma[c] -= (ma[c] - mb[c]) / k * k;
        if (ma[c] != mb[c]){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}


int32_t main(){
    cl = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cin.tie(nullptr);
#ifdef _MY
    freopen("VimProject/input.txt", "r", stdin);
    freopen("VimProject/output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}