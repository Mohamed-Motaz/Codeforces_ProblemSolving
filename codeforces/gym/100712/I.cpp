#include <iostream>
#include <stdio.h>
#include <functional>
#include <string>
#include <cstring>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <iomanip>
#include <complex>
#include <unordered_set>
#include <assert.h>
#include <sstream>

using namespace std;
const int maxn=3e2+10;
const int maxm=1e6+10;
const int INF=0x3f3f3f3f;
typedef long long ll;
typedef unsigned long long ull;
#define tpyeinput int
#define show(x) cout<<#x<<"="<<x<<endl
inline bool read(tpyeinput &num){int flag=1,ch=getchar();if(ch==EOF) return false;num=0;while(ch<'0'||ch>'9'){if(ch=='-') flag=-1;ch=getchar();}while(ch>='0'&&ch<='9'){num=num*10+ch-'0',ch=getchar();}num*=flag;return true;}
inline bool read(tpyeinput &num1,tpyeinput &num2){return read(num1)&&read(num2);}
inline bool read(tpyeinput &num1,tpyeinput &num2,tpyeinput &num3){return read(num1)&&read(num2)&&read(num3);}
inline bool read(tpyeinput &num1,tpyeinput &num2,tpyeinput &num3,tpyeinput &num4){return read(num1)&&read(num2)&&read(num3)&&read(num4);}
int casn,n,m;
char s[maxn];
int add[maxn];
int t[maxn];
int main(){
//#define test
#ifdef test
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif

    read(casn);
    while(casn--){
        scanf("%s",s+1);
        int f=0;
        int len=strlen(s+1);
        for(int k=len;k>1;k--){
            for(int i=0;i<10;i++){
                memset(add,0,sizeof add);
                for(int j=1;j<=len;j++) t[j]=s[j]-'0';
                int tmp=0;
                for(int j=1;j+k-1<=len;j++){
                    tmp-=add[max(j-k,0)];
                    int y=0;
                    t[j]=(t[j]+tmp)%10;
                    if(t[j]==i) continue;
                    if(i>t[j]) y=(i-t[j]);
                    else y=(i+10-t[j]);
                    add[j]=y;
                    t[j]=i;
                    tmp+=y;
                }
                int flag=1;
                for(int j=len-k+2;j<=len;j++){
                    tmp-=add[max(j-k,0)];
                    if((t[j]+tmp)%10!=i){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    printf("%d\n",k);
                    f=1;
                    break;
                }
            }
            if(f) break;
        }
        if(f==0) puts("1");
    }

#ifdef test
    fclose(stdin);
//    fclose(stdout);
//    system("out.txt");
#endif
    return 0;
}