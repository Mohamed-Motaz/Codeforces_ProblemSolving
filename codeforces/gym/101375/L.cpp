#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <set>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double>
#define all(a) a.begin(), a.end()
#define pi acos(-1)
#define mod 998244353
using namespace std;
int n, t;
const ll N = 1e5 + 3;
vector<ll> odd;


int main() {
    HS;
    cin>>n;



    int od=0;

    long long sum=0;

    int x;

    for(int i=0;i<n;i++){

        cin>>x;

        if(x%2==0)sum+=x;

        else {

            odd.push_back(x);

        }
    }
    //cout << sum << endl;
    sort(odd.begin(), odd.end(),greater<int>());
    //for(auto e: odd) cout << e << " ";
    //cout << endl;;
    if (odd.size() > 1){
        if (odd.size() % 2) odd.pop_back();
        for (int i = 0; i < odd.size(); i++){
            sum += odd[i];
        }

    }
    cout << sum;



}