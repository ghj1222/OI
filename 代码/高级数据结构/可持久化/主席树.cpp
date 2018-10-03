#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn =2e5+5;
int mian(){
    int s=0,f=1;char ch;
    while(!isdigit(ch=getchar()))(ch=='-')&&(f=-1);
    for(s=ch-'0';isdigit(ch=getchar());s=s*10+ch-'0');
    return s*f;
}
/*
徨工の扮の知は冱えますか
    その知すら 控に 普てたのは
*/
struct FFF{
    int sum;
    FFF* ch[2];
    FFF(){sum=0;ch[0]=ch[1]=0;}
};
typedef FFF* ptr;
ptr root[maxn];
int a[maxn],b[maxn];
int n,_n,m;
void add(ptr last,ptr& th,int v,int l=1,int r=n){
    th=new FFF;*th=*last;th->sum++;
    if(l==r)return;
    int mid=l+r>>1;
    if(v<=mid)add(last->ch[0],th->ch[0],v,l,mid);
    else      add(last->ch[1],th->ch[1],v,mid+1,r);
}
int getid(ptr last,ptr th,int k,int l=1,int r=n){
    if(l==r)return l;
    int tmp=th->ch[0]->sum-last->ch[0]->sum;
    int mid=l+r>>1;
    if(k<=tmp)return getid(last->ch[0],th->ch[0],k,l,mid);
    else {k-=tmp;return getid(last->ch[1],th->ch[1],k,mid+1,r);}
}
int main(){
    root[0]=new FFF;
    root[0]->ch[0]=root[0]->ch[1]=root[0];
    _n=mian();m=mian();
    for(int i=1;i<=_n;++i){
        b[i]=a[i]=mian();
    }
    sort(b+1,b+1+_n);
    n=unique(b+1,b+1+_n)-b-1;
    for(int i=1;i<=_n;++i){
        add(root[i-1],root[i],lower_bound(b+1,b+1+n,a[i])-b);
    }
    while(m--){
        int l=mian(),r=mian(),k=mian();
        cout<<b[getid(root[l-1],root[r],k)]<<endl;
    }
    return 0;
}