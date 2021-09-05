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
   
int main()
{  
   
   Bedoazim;

   int k;

   string n, m;

   cin >> k;

   cin >> n >> m;

   int comm = 0;

   for (int i = 0; i < n.size(); i++) {

       if (n[i] == m[i])
           comm++;

   }

   cout << min(comm,k) + (n.size()-max(comm,k));


}