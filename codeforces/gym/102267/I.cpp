#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<sstream>
#include<stack>
#include<string>
#include<set>
#include<vector>
using namespace std;
#define PI acos(-1.0)
#define EXP exp(1)
#define pppp cout<<endl;
#define EPS 1e-8
#define ULL unsigned long long     //1844674407370955161
#define INT_INF 0x3f3f3f3f      //1061109567
#define LL_INF 0x3f3f3f3f3f3f3f3f //4557430888798830399
// ios::sync_with_stdio(false);
// 那么cin, 就不能跟C的 scanf，sscanf, getchar, fgets之类的一起使用了。
const int dr[]= {0, 0, -1, 1, -1, -1, 1, 1};
const int dc[]= {-1, 1, 0, 0, -1, 1, -1, 1};
char ds[]={'L','R','U','D'};
inline int read()//输入外挂
{
    int ret=0, flag=0;
    char ch;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        ret = ch - '0';
    while((ch=getchar())>='0'&&ch<='9')
        ret=ret*10+(ch-'0');
    return flag ? -ret : ret;
}
const int maxn=1000050;
int num[maxn];
int vis[maxn];//0表示左括号，-1表示右括号
stack<int> s1;
stack<int> s2;
int main()
{

    int n;
    scanf("%d",&n);
    string s;
    cin>>s;
    s="("+s+")";
    //cout<<s<<endl;
    int cnt=0;
    int Num=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(')
            vis[++cnt]=0;
        else if(s[i]==')')
            vis[++cnt]=-1;
        else
        {
            for( ; ; ++i)
            {
                if(s[i]=='(' || s[i]==')')
                {
                    --i;
                    vis[++cnt]=Num;
                    Num=0;
                    break;
                }
                Num=Num*10+s[i]-'0';
            }
        }
    }
    //for(int i=1;i<=cnt;++i)
        //cout<<vis[i]<< " ";
    s1.push(0);//数字
    s2.push(0);//括号
    for(int i=2;i<=cnt;++i)
    {
        if(vis[i]!=0 && vis[i]!=-1)
        {
            num[vis[i]]=s1.top();
            s1.push(vis[i]);
        }
        else if(vis[i]==0)
            s2.push(0);
        else if(vis[i]==-1)
        {
            s1.pop();
            s2.pop();
        }
    }
    for(int i=1;i<n;++i)
        printf("%d ",num[i]);
    printf("%d\n",num[n]);
    return 0;
}