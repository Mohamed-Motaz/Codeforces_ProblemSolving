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

const long long mod = 1e9 + 7, N = 3e5 + 5, inf = -1e17;

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

void gcd(int a, int b) {

    int g = 0;

    if (b == 0) {

        g += a;
    }

    else {

        gcd(b, a % b);
    }

}


int main()
{

    Bedoazim;

    long long n, m;

    int x1, x2, y1, y2;

    cin >> n >> m;

    cin >> x1 >> y1 >> x2 >> y2;

    long long total=0;

    total += (n - x2) * m;

    if (m % 2 != 0)
        total -= (n - x2) * (m - 1);
        
    else
        total -= (n - x2) * (m);

    total += ((x2 - x1) + 1) * (m - y2);

    if ((m - y2) % 2 != 0)
        total -= ((x2 - x1) + 1) * ((m - y2) - 1);

    else
        total -= ((x2 - x1) + 1) * (m - y2);

    total += ((x2-x1)+1) * (y1-1);

    if ((y1-1) % 2 != 0)
        total -= ((x2 - x1) + 1) * ((y1-1) - 1);

    else
        total -= ((x2 - x1) + 1) * (y1-1);

    total += (x1-1) * m;

    if (m % 2 != 0)
        total -= (x1-1) * (m - 1);

    else
        total -= (x1-1) * (m);




    if (total % 2 == 0)
        cout << total / 2;

    else
        cout << (total + 1) / 2;

    
}