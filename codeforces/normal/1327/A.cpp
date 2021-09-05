#include <iostream>
#define ll long long
using namespace std;

int main()
{
	ll t;
	ll a,b;
	cin>>t;
	for(int i=0;i<t;i++){
        cin>>a>>b;
        if (a%2 == b%2 && a >= b * b)
            cout<<"YES"<<endl;

        else
            cout<<"NO"<<endl;
        }


	return 0;
}