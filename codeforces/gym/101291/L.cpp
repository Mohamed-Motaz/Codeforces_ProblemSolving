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


    
int main()
{   

    Bedoazim;

    int arr[5], ar[5];
    
    int max = 0, id = -1;

    for (int i = 0; i < 3; i++) {
     
        cin >> arr[i] >> ar[i];

        if (max < arr[i])
            max = arr[i], id = i;

    }
    int total = 0, ans = 0;

    for (int i = 0; i < 3; i++) {

        if (i == id)
            continue;

        if (i != id)
            ans = ar[i];


        total += arr[i];
    }
    if (total == max && ans + ar[id] == max)
        cout << "YES";

    else if (total == (max * 2)) {

        ans = 0;

        for (int i = 0; i < 3; i++) {

            ans += ar[i];
        }
        if (ans == total + max)
            cout << "YES";

        else
            cout << "NO";
    }

    else
        cout << "NO";

}