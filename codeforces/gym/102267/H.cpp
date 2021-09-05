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

    double n, m;

    cin >> n >> m;

    double angle = (360 / (n * 2));

    double r = m / (2 * sin((angle * pi) / 180));

    double area = pi * (r * r);

    cout << setprecision(8) << fixed << area;

}