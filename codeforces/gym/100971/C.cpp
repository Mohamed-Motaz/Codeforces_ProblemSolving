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


long long ans = 0, arr[25];

int n;

vector<long long>v;

void rec(int ind) {

    if (ind == n) {

        return;
    }

    v.push_back(arr[ind]);
    long long an = 0;
    //cout << v[0] << " ";
    for (int i = 0; i < v.size(); i++) {
        an = an | v[i];
        //cout << v[i] << ' ';
    }
    //cout << endl;
    ans += an;
    rec(ind + 1);
    v.pop_back();
        

    rec(ind + 1);

}




int main()
{

    Bedoazim;

    long long arr[N], n;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    if (((arr[1] + arr[0]) - 1) + arr[0] > arr[n - 1]) {
        cout << "YES" << endl;
        cout << (arr[1] + arr[0]) - 1;
    }
    else
        cout << "NO";

}