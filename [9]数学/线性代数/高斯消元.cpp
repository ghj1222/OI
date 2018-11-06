#include <bits/stdc++.h>
using namespace std;
int n;
struct fangcheng
{
	double a[105],b;
	fangcheng operator*(double b)
	{
		fangcheng ans(*this);
		for(int i=1;i<=n;i++) ans.a[i]*=b;
		ans.b*=b; return ans;
	}
	fangcheng operator/(double b)
	{
		fangcheng ans(*this);
		for(int i=1;i<=n;i++) ans.a[i]/=b;
		ans.b/=b; return ans;
	}
	fangcheng operator-(fangcheng b)
	{
		fangcheng ans(*this);
		for(int i=1;i<=n;i++) ans.a[i]-=b.a[i];
		ans.b-=b.b; return ans;
	}
}a[105];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			scanf("%lf",&a[i].a[j]);
		scanf("%lf",&a[i].b);
	}
	for(int i=1;i<=n;i++)//依次消除每一列 
	{
		if(a[i].a[i]==0){puts("No Solution");return 0;}
		a[i]=a[i]/a[i].a[i];
		for(int j=1;j<=n;j++)
			if(j==i)continue;
			else a[j]=a[j]-a[i]*a[j].a[i];
	}
	for(int i=1;i<=n;i++)
		printf("%.2lf\n",a[i].b);
}
