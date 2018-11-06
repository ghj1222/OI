#include<bits/stdc++.h>
using namespace std;//以前写的代码 马风不太好见谅
struct vesor
{
	double x,y,p;
	vesor(double x=0,double y=0):x(x),y(y){}
	friend vesor operator-(const vesor&a,const vesor&b){return vesor(a.x-b.x,a.y-b.y);}
	friend double operator^(const vesor&a,const vesor&b){return a.x*b.y-a.y*b.x;}
	double mod(){return sqrt(x*x+y*y);}
}a[10010];
bool youngsc(const vesor&a,const vesor&b){return a.p<b.p;}
bool vis[10010];
int s[10010],top,minj=1,n;
double ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a[i].x,&a[i].y);
		if(a[minj].y>a[i].y||(a[minj].y==a[i].y&&a[minj].x>a[i].x))
			minj=i;
	}
	swap(a[1],a[minj]);
	for(int i=2;i<=n;i++)
		a[i].x-=a[1].x,a[i].y-=a[1].y,a[i].p=atan2(a[i].y,a[i].x);
	sort(a+2,a+1+n,youngsc);
	a[1].x=0,a[1].y=0,s[1]=1,s[2]=2,s[3]=3,top=3;
	for(int i=4;i<=n;i++)
	{
		while(top>2&&((a[s[top]]-a[s[top-1]])^(a[i]-a[s[top]]))<0)
			top--;
		s[++top]=i;
	}
	for(int i=1;i<top;i++)
		ans+=(a[s[i+1]]-a[s[i]]).mod();
	ans+=(a[n]-a[1]).mod();
	printf("%.2f\n",ans);
	return 0;
}