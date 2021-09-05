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

const long long mod = 1e9 + 7, N = 2e5 + 9, inf = 1e18;

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

int n;

long long timee[N], dp[N],damage[N];

long long solve(int i,long long tim) {

    if (i == n+1) {

        return 0;
    }

    if (dp[i] != -1)
        return dp[i];

    //cout << i << " " << timee[i] << " " << tim << endl;

    long long ans = 1 + solve(i + 1,tim+(timee[i]-timee[i-1]));

    if (abs(timee[i]-timee[i-1])+tim >= damage[i]) {

        ans = min(ans, solve(i + 1, ((tim + (abs(timee[i - 1] - timee[i]))) - damage[i])));
    
    }

    //cout << i << " " << timee[i] << " " << tim << endl;
    
    return dp[i] = ans;
}

int main()
{

    Bedoazim;

    for (int i = 0; i < N; i++)
        dp[i] = -1;


    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> timee[i] >> damage[i];

    timee[0] = 0;

    cout << solve(1, 0) + 1;

}