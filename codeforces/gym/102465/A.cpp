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
#define ll long long
#define endl '\n'
#define Bedoazim ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

const long long mod = 1e9 + 7, N = 2e4 + 9, inf = -1e17;

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


int main() {
    
    Bedoazim;
	
		int n;

		string s, m;

		map<string, int>mp;

		cin >> n >> s;

			m = s[0];

			
		for (int i = 1; i < n; i++){

				if (s[i] == s[i - 1])
					m += s[i];

				else if (i == n - 1)
					mp[m]++;

				else{

					mp[m]++;

					m = s[i];
				}
			
		}

			int min = 1e3;

			for (auto el : mp)
				if (el.second < min)
					min = el.second;
	
			if (n % min == 0) {

				int size = n / min;

				vector<string>v;
				int i = 0;

				while (i < n) {

					string tmp = s.substr(i, size);

					v.push_back(tmp);

					i += size;
				}

				bool done = false;
				int ans = 0;

				for (int i = 0; i < v.size() - 1; i++) {

					for (int j = 0; j < size; j++) {

						if (v[i][j] != v[i + 1][j]) {

							done = true;

							break;
						}
					}
				}

				if (!done)
					cout << mp.size() << endl;

				else {

					string t;

					t= s[0];


					for (int i = 1; i < n; i++) {

						if (s[i] == s[i - 1])
							t += s[i];

						else if (i == n - 1)
							ans++;

						else {

							ans++;

							t = s[i];
						}
					}

					cout << ans << endl;

				}

			}
			else
				cout << mp.size();
		


		
}