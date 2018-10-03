#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
struct node{
    node *fa,*ch[2];
    int k,siz,rev;
    node(){fa=ch[1]=ch[0]=NULL;k=rev=0;siz=1;}
    bool d(){return fa->ch[1]==this;}
    void r(){swap(ch[0],ch[1]);rev^=1;}
    void up(){
        siz=1;
        if(ch[0]!=NULL)siz+=ch[0]->siz;
        if(ch[1]!=NULL)siz+=ch[1]->siz;
    }
    void down(){
        if(!rev)return;
        if(ch[0]!=NULL)ch[0]->r();
        if(ch[1]!=NULL)ch[1]->r();
        rev=0;
    }
    int rk(){int si=1;if(ch[0]!=NULL)si+=ch[0]->siz;return si;}
};
typedef node* ptr;
int a[maxn];
ptr root;
ptr newnode(const int &k){ptr p=new node;p->siz=1;p->k=k;return p;}
void rot(ptr x){
    ptr y=x->fa,z=y->fa;int k=x->d();ptr w=x->ch[!k];
    y->down();x->down();
    if(z!=NULL)z->ch[y->d()]=x;
    x->ch[!k]=y;y->ch[k]=w;
    x->fa=z;y->fa=x;
    if(w!=NULL)w->fa=y;
    y->up();x->up();
    if(z==NULL)root=x;
}
void splay(ptr x,ptr o){
    if(x==NULL)return;
    static ptr st[maxn];
    int top;st[top=1]=x;
    while(st[top]->fa!=NULL)st[top+1]=st[top]->fa,top++;
    while(top)st[top--]->down();
    while(x->fa!=o){
        if(x->fa->fa!=o)rot(x->d()==x->fa->d()? x->fa:x);
        rot(x);
    }
    x->up();
    if(o==NULL)root=x;
}
ptr build(int l,int r){
    if(l>r)return NULL;
    int mid=l+r>>1;
    ptr p=newnode(a[mid]);
    if(l==r)return p;
    p->ch[0]=build(l,mid-1);
    p->ch[1]=build(mid+1,r);
    if(p->ch[0]!=NULL)p->ch[0]->fa=p;
    if(p->ch[1]!=NULL)p->ch[1]->fa=p;
    p->up();
    return p;
}
int rnk(const int &k,ptr o){
    if(o==NULL)return 0;
    int si=o->rk();
    if(k==o->k)return si;
    o->down();
    if(k>o->k){return si+rnk(k,o->ch[1]);}
    else {return rnk(k,o->ch[0]);}
}
ptr kth(const int &k,ptr o){
    if(o==NULL)return NULL;
    int s=o->rk();
    if(s==k)return o;
    o->down();
    if(k>s) return kth(k-s,o->ch[1]);
    else return kth(k,o->ch[0]);
}
void out(ptr x){
    if(x!=NULL){
        x->down();
        out(x->ch[0]);
        if(x->k!=0x7fffffff&&x->k!=-0x7fffffff)cout<<x->k<<' ';
        out(x->ch[1]);
    }
}
int read(){
    int s=0,f=1;char ch;
    while(!isdigit(ch=getchar()))(ch=='-')&&(f=-1);
    for(s=ch-'0';isdigit(ch=getchar());s=s*10+ch-'0');
    return s*f;
}
int main(){
    int n,m;
    n=read(),m=read();
    for(int i=1;i<=n;++i){
        a[i]=i;
    }
    a[0]=-0x7fffffff;a[n+1]=0x7fffffff;
    root=build(0,n+1);
    while(m--){
        int x=read(),y=read();
        splay(kth(x,root),NULL);
        splay(kth(y+2,root),root);
        root->ch[1]->ch[0]->r();
    }
    out(root);
}
