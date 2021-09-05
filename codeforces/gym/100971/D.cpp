#include<bits/stdc++.h>
using namespace std;
#define ll __int64
#define mod 100000007
#define esp 0.00000000001
const int N=2e5+10,M=1e6+10,inf=1e9+10;
struct is
{
    int x,val;
    int pos;
}a[N];
int cmp(is x,is y)
{
    return x.x<y.x;
}
int d[N],k;
int l[N],r[N];
int ans[N];
int check(int x,int len)
{
    if(x<1||x>len)
    return 0;
    return 1;
}
int main()
{
    int x,y,z,i,t;
    scanf("%d",&x);
    for(i=1;i<=x;i++)
    scanf("%d%d",&a[i].x,&a[i].val),a[i].pos=i;
    sort(a+1,a+1+x,cmp);
    a[0].val=a[x+1].val=inf;
    k=0;
    d[++k]=0;
    for(i=1;i<=x;i++)
    {
        while(a[d[k]].val<a[i].val)k--;
        l[i]=d[k];
        d[++k]=i;
    }
    k=0;
    d[++k]=x+1;
    for(i=x;i>=1;i--)
    {
        while(a[d[k]].val<a[i].val)k--;
        r[i]=d[k];
        d[++k]=i;
    }
    for(i=1;i<=x;i++)
    {
        int u=check(l[i],x),v=check(r[i],x);
        if(u&&v)
        {
            if(a[i].x-a[l[i]].x>a[r[i]].x-a[i].x)
            ans[a[i].pos]=a[r[i]].pos;
            else if(a[i].x-a[l[i]].x<a[r[i]].x-a[i].x)
            ans[a[i].pos]=a[l[i]].pos;
            else
            {
                if(a[l[i]].val>a[r[i]].val)
                ans[a[i].pos]=a[l[i]].pos;
                else
                ans[a[i].pos]=a[r[i]].pos;
            }
        }
        else if(u)
        ans[a[i].pos]=a[l[i]].pos;
        else if(v)
        ans[a[i].pos]=a[r[i]].pos;
        else
        ans[a[i].pos]=-1;
    }
    for(i=1;i<=x;i++)
    printf("%d ",ans[i]);
    return 0;
}