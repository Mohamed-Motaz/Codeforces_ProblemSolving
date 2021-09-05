
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    double x1,x2,vx1,vx2,y1,y2,vy1,vy2;
    cin>>x1>>y1>>x2>>y2>>vx1>>vy1>>vx2>>vy2;
    double a=x1-x2;
    double b=vx1-vx2;
    double A=y1-y2;
    double B=vy1-vy2;
    double ans;
    if(B*B+b*b==0)
    {
        ans=sqrt(a*a+A*A);
        printf("%.15lf\n",ans);
        return 0;
    }
//    cout<<a<<" "<<b<<" "<<A<<" "<<B<<endl;
    double k=(-1.0)*(A*B+a*b)/(b*b+B*B);
    double ans1=a*a+A*A+2*(A*B+a*b)*k+(B*B+b*b)*k*k;
//    cout<<sqrt(a*a+A*A)<<endl;
//    cout<<k<<" "<<ans1<<endl;
    ans=sqrt(ans1);
    if(k>=0) printf("%.15lf\n",ans);
    else {
        ans=sqrt(a*a+A*A);
        printf("%.15lf\n",ans);
    }
    return 0;
}