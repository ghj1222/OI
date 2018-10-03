#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 3e5+5;
int mian(){
    int s=0,f=1;char ch;
    while(!isdigit(ch=getchar()))(ch=='-')&&(f=-1);
    for(s=ch-'0';isdigit(ch=getchar());s=s*10+ch-'0');
    return s*f;
}
struct node{
    node* fa,*ch[2];
    int sum,val,rev;
    node(){sum=val=rev=0;fa=ch[0]=ch[1]=NULL;}
    bool d(){return fa->ch[1]==this;}
    bool ntr(){return fa!=NULL&&(fa->ch[0]==this||fa->ch[1]==this);}
    void r(){swap(ch[0],ch[1]);rev^=1;}
    void up(){
        sum=val;
        if(ch[0])sum^=ch[0]->sum;
        if(ch[1])sum^=ch[1]->sum;
    }
    void down(){
        if(!rev)return;
        if(ch[0])ch[0]->r();
        if(ch[1])ch[1]->r();
        rev=0;
    }
};
node s[maxn];
typedef node *ptr;
void rot(ptr x){
    ptr y=x->fa,z=y->fa;int k=x->d();ptr w=x->ch[!k];
    if(y->ntr())z->ch[y->d()]=x;
    x->ch[!k]=y;y->ch[k]=w;x->fa=z;y->fa=x;
    if(w)w->fa=y;
    y->up();
}
void splay(ptr x){
    static ptr st[maxn];
    int top;st[top=1]=x;
    while(st[top]->ntr())st[top+1]=st[top]->fa,top++;
    while(top)st[top--]->down();
    while(x->ntr()){
        if(x->fa->ntr())rot(x->d()==x->fa->d()? x->fa:x);
        rot(x);
    }
    x->up();
}
void access(ptr x){
    for(ptr y=NULL;x;x=(y=x)->fa){
        splay(x);x->ch[1]=y;x->up();
    }
}
void makeroot(ptr x){
    access(x);splay(x),x->r();
}
ptr findroot(ptr x){
    access(x),splay(x);
    while(x->down(),x->ch[0]!=NULL)x=x->ch[0];
    splay(x);
    return x;
}
void link(ptr x,ptr y){
    if(findroot(x)==findroot(y))return;
    makeroot(x);x->fa=y;
}
void cut(ptr x,ptr y){
    makeroot(x);access(y),splay(y);
    if(y->ch[0]==x){
        y->ch[0]=x->fa=NULL;
    }
}
int q(ptr x,ptr y){
    makeroot(x);access(y);splay(y);
    return y->sum;
}
void change(ptr x,const int &k){
    splay(x);
    x->val=k;x->up();
}
int n,m;
int main(){
    n=mian(),m=mian();
    for(int i=1;i<=n;++i)s[i].val=mian(),s[i].up();
    for(int i=1;i<=m;++i){
        int op=mian(),x=mian(),y=mian();
        if(op==0)printf("%d\n",q(s+x,s+y));
        if(op==1)link(s+x,s+y);
        if(op==2)cut(s+x,s+y);
        if(op==3)change(s+x,y);
    }
    return 0;
}
