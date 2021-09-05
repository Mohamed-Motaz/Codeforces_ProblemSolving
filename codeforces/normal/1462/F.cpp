#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 2000 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int> , null_type,less<pair<int, int> >, rb_tree_tag,tree_order_statistics_node_update>


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--){
        ordered_set l,r;

        int n; cin >> n;
        int ans = n;

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n ; i++){
            cin >> v[i].first >> v[i].second;
            l.insert({v[i].first, i});
            r.insert({v[i].second, i});
        }
        
        for (int i = 0; i < n ; i++){
            ans = min(ans,
                    (int)(r.order_of_key({v[i].first, -1}) + (n - l.order_of_key({v[i].second, n + 11}))));
        }
        cout << ans << endl;
        
    }

    return 0;
}