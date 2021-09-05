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
ll arr[200000];
int n, t;



int main() {
    HS;
    int n;
    cin >> n;

    long long x,y,sum;

    for(int ii=0;ii<n;ii++){

        cin>>x>>y;

        sum=x+y;

        if(sum%2==0&&x==sum/2)cout<<"Ok"<<endl;

        else if(sum%2!=0&&(x==sum/2||y==sum/2))cout<<"Ok"<<endl;

        else if(sum%2==0)cout<<sum/2<<" "<<sum/2<<endl;

        else
            cout<<sum/2<<" "<<(sum/2)+1<<endl;


    }

}