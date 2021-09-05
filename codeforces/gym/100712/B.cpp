#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
clock_t T;
#define ctime cerr <<endl<< "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define debug(x) cout << (#x) << " " << (x) <<" "<< endl
#define debug2(x, y) cerr << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< endl
#define debug3(x, y, z) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << endl
#define marwan ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);ios_base::sync_with_stdio(0);
#define read freopen("input.txt", "r", stdin);
#define write  freopen("output.txt", "w", stdout);
#define f(a, b, c) for(ll a = b; a < c; a++)
#define fr(a, b, c) for(int a = b; a >= c; a--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define cinvec(v, n) f(i, 0, n){ll a;cin>>a;v.pb(a);};
#define printvec(v, n) for (auto e: v) cout << e << " "; cout << endl;
#define pb push_back
#define pf push_front
#define RESET(a, b) memset(a, b, sizeof(a))
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double pi = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
using namespace std;


//
//0
//4
//6
//1
//6
//5


int main() {

#ifdef offline_debug
    read
#endif
    marwan

    ll t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> R(n + 1, 0),P(n + 1, 0),S(n + 1, 0);
        vector<int> RR(n + 1, 0),PP(n + 1, 0),SS(n + 1, 0);
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'R')
                RR[i + 1]++;
            if (s[i] == 'S')
                SS[i + 1]++;
            if (s[i] == 'P')
                PP[i + 1]++;
            RR[i + 1] += RR[i],
            PP[i  +1] += PP[i],
            SS[i + 1] += SS[i];
        }
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'R')
                P[i + 1]++;
            if (s[i] == 'P')
                S[i + 1]++;
            if (s[i ] == 'S')
                R[i + 1]++;

            R[i + 1] += R[i],
            P[i + 1] += P[i],
            S[i + 1] += S[i];
        }
        //printvec(R, n);
        //printvec(P, n);
        //printvec(S, n);
        int ctr = 0;
        //R R P S S
        //i = 2, j = 1,
        for (int i = 0; i <= n; i++){
            //i is the num of rock
            for (int j = 0; j <= n; j++){
                //j is the num of paper
                if (i + j > n)
                    break;

                int winsWithRock = SS[i];
                int winsWithPaper = RR[j + i] - RR[i];
                int winsWithSis = PP[n] - PP[i + j];
                int sum = winsWithRock + winsWithPaper + winsWithSis;

                int otherWinsWithMeAsRock = PP[i];
                int otherWinsWithMeAsPaper = SS[j + i] - SS[i];
                int otherWinsWithMeAsSis = RR[n] - RR[i + j];
                int otherSUm = otherWinsWithMeAsRock + otherWinsWithMeAsPaper + otherWinsWithMeAsSis;
                if (sum > otherSUm)
                    ctr++;
            }
       }
        cout << ctr << endl;
    }
    return 0;
}