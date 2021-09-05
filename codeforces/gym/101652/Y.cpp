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

const long long mod = 1e9 + 7, N = 1e5 + 9, inf = 1e18;

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

long long dp[N][5], ai[N], bi[N], ci[N], n;

long long solve(int ind,int prev) {
  
    if (ind == n)
        return 0;

    if (dp[ind][prev] != -1)
        return dp[ind][prev];

    long long a = 0, b = 0, c = 0;

    if (prev != 1)
        a = ai[ind] + solve(ind + 1, 1);

    if (prev != 2)
        b = bi[ind] + solve(ind + 1, 2);

    if (prev != 3)
        c = ci[ind] + solve(ind + 1, 3);

    return dp[ind][prev]=max(a,max(b,c));
}

int main()
{

    Bedoazim;

    for (int i = 0; i <= N; i++)
        for (int ii = 0; ii <= 5; ii++)
            dp[i][ii] = -1;
    
    int x, k, p;

    cin >> k >> p >> x;

    long double ans = inf;

    for (int i = 1; i < 1e7; i++) {

       long double m = ((double)x * i) + ((double)((double)k / i) * p);

       if (m < ans)
           ans = m;

    }

    cout << setprecision(3) << fixed << ans;

}