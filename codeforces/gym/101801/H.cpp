#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline long long read()
{
	long long kk=0,f=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){if(cc=='-')f=-1;cc=getchar();}
	while(cc>='0'&&cc<='9'){kk=(kk<<1)+(kk<<3)+cc-'0';cc=getchar();}
	return kk*f;
}
int n,ca,cb,fath[100011];LL tot=0;
LL tim=0,ru[100011],num[100011];
list<int>edge[100011];
void add(int a,int b)
{
	edge[a].push_back(b);
	edge[b].push_back(a);
}
void dfs(int a,int fa)
{
	ru[a]=tim++;
	fath[a]=fa;
	list<int>::iterator it=edge[a].begin();
	for(;it!=edge[a].end();++it)
	{
		if(*it!=fa)
		{
			dfs(*it,a);
		}
	}
	num[a]=tim-ru[a];
}
void dfs2(int a)
{
	if(a==ca)return;
	int li=fath[a];dfs2(li);
	tot+=(num[li]-num[a])*num[a];
}
int main()
{
	int T=read();
	while(T--)
	{
		n=read();ca=read();cb=read();tim=0;tot=0;
		memset(ru,0,sizeof(ru));
		memset(num,0,sizeof(num));
		memset(fath,0,sizeof(fath));
		for(int i=0;i<=n+10;++i)edge[i].clear();
		for(int i=1;i<n;++i)
		{
			add(read(),read());
		}
		dfs(ca,0);
		dfs2(cb);
		cout<<tot<<endl;
	}
 }