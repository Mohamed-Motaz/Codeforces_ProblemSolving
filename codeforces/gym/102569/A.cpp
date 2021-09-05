#include <iostream>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<cmath>
#include<stack>
#include <cctype>
#include <cstdio>
#define pi acos(-1)
#define endl '\n'
#define Bedoazim ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

const long long mod = 1e9 + 7, N = 5e5 + 9, inf = 1e18;

set<long long> GetDivisors(long long val) {

    set<long long> st;
 
    for (int i = 1; i <= sqrt(val); i++) {

        if (val % i == 0) {
            st.insert(i);
            st.insert(val / i);
        }
    }
    return st;
}


    
int main()
{   

    Bedoazim;

    long long arr[N], n, q, l, r, a;

    cin >> n;
    
    long long ans = 0;

    for (int i = 0; i < n; i++) {

        cin >> arr[i];

    }
   
    cin >> q;

    cin >> r >> l >> a;

    for (int i = r-1; i <= l-1; i++) {

        arr[i] += a;
    }

    for (int i = 0; i < n; i++) {

       // cout << arr[i] << " ";

        ans = arr[i] - ans;

    }

    //cout<<endl;

    //cout << ans;

    //return 0;

    cout << ans << endl;

    for (int i = 0; i < q - 1; i++) {

        cin >> r >> l >> a;

        if(((l-r)+1)%2!=0)
        ans += a;

        cout << ans << endl;

    }




}