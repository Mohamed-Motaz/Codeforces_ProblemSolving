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

    long long a, b, a1, a2,b1,b2;

    cin >> a >> b;

    cin >> a1 >> b1;

    cin >> a2 >> b2;

    bool found = false;

    if (a1 + a2 <= a && b1 <= b && b2 <= b)
        found = true;

    else if (a1 + a2 <= b && b1 <= a && b2 <= a)
        found = true;
    
    else if (a1 + b2 <= a && b1 <= b && a2 <= b)
        found = true;

    else if (a1 + b2 <= b && b1 <= a && a2 <= a)
        found = true;

    else if (b1 + a2 <= a && a1 <= b && b2 <= b)
        found = true;

    else if (b1 + a2 <= b && a1 <= a && b2 <= a)
        found = true;

    else if (b1 + b2 <= a && a1 <= b && a2 <= b)
        found = true;

    else if (b1 + b2 <= b && a1 <= a && a2 <= a)
        found = true;

    if (!found)
        cout << "NO";

    else
        cout << "YES";


}