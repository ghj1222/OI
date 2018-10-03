// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<queue>
#include<ctime>
using namespace std;
const int maxn = 3e6+5;
int mian(){
    int s=0,f=1;char ch;
    while(!isdigit(ch=getchar()))(ch=='-')&&(f=-1);
    for(s=ch-'0';isdigit(ch=getchar());s=s*10+ch-'0');
    return s*f;
}
struct node{
    node* ch[2];
    int k,siz;
    void up(){siz=1+ch[0]->siz+ch[1]->siz;}
};
typedef node* ptr;
ptr root,null;
ptr bc[maxn];
int top;
ptr newnode(int k){
    static node s[maxn],*tail=s;
    ptr p=top? bc[--top]:tail++;
    p->ch[0]=p->ch[1]=null;
    p->siz=1;p->k=k;
    return p++;
}
void rot(ptr &x,bool d){
    ptr w=x->ch[!d];
    x->ch[!d]=w->ch[d];w->ch[d]=x;w->siz=x->siz;
    x->up();x=w;
}
void maintain(ptr &x,bool d){
    if(x->ch[d]->ch[d]->siz>x->ch[!d]->siz)rot(x,!d);
    else{
        if(x->ch[d]->ch[!d]->siz>x->ch[!d]->siz){
            rot(x->ch[d],d);rot(x,!d);
        }else return;
    }
    maintain(x->ch[0],0);maintain(x->ch[1],1);
    maintain(x,0);maintain(x,1);
}

void ins(int k,ptr &o=root){
    if(o==null){o=newnode(k);return;}
    o->siz++;
    if(k<o->k)ins(k,o->ch[0]);
    else ins(k,o->ch[1]);
    maintain(o,k>=o->k);
}

int del(int k,ptr &x=root){
    x->siz--;
    int tmp;
    if(k==x->k||(k<x->k&&x->ch[0]==null)||(k>x->k&&x->ch[1]==null)){
        tmp=x->k;
        if(x->ch[0]==null){bc[top++]=x;x=x->ch[1];return tmp;}
        if(x->ch[1]==null){bc[top++]=x;x=x->ch[0];return tmp;}
        x->k=del(x->k+1,x->ch[0]);
        return tmp;
    }
    if(k<x->k) tmp=del(k,x->ch[0]);
    else tmp=del(k,x->ch[1]);
    return tmp;
}

int rnk(int k,ptr x=root){
    if(x==null)return 1;
    if(k<=x->k)return rnk(k,x->ch[0]);
    else return x->ch[0]->siz+1+rnk(k,x->ch[1]);
}
int kth(int k,ptr x=root){
    if(k==x->ch[0]->siz+1)return x->k;
    if(k<=x->ch[0]->siz)return kth(k,x->ch[0]);
    else return kth(k-1-x->ch[0]->siz,x->ch[1]);
}
int prev(int k,ptr x=root){
    if(x==null)return k;int tmp;
    if(k<=x->k)tmp=prev(k,x->ch[0]);
    else {tmp=prev(k,x->ch[1]);if(tmp==k)tmp=x->k;}
    return tmp;
}
int succ(int k,ptr x=root){
    if(x==null)return k;int tmp;
    if(k>=x->k)tmp=succ(k,x->ch[1]);
    else {tmp=succ(k,x->ch[0]);if(tmp==k)tmp=x->k;}
    return tmp;
}
void out(ptr o=root){
    if(o!=null){
        out(o->ch[0]);
        cout<<o->k<<' ';
        out(o->ch[1]);
    }
}
void pout(){
    queue<pair<ptr,int> >q;q.push(make_pair(root,1));
    int now=1;
    while(!q.empty()){
        auto t=q.front();q.pop();
        if(now!=t.second)putchar('\n'),now=t.second;
        cout<<t.first->k<<' ';
        if(t.first->ch[0]!=null)q.push(make_pair(t.first->ch[0],t.second+1));
        if(t.first->ch[1]!=null)q.push(make_pair(t.first->ch[1],t.second+1));
    }
    printf("\nheight:%d\n",now);
}
int main(){
    null=new node;
    null->siz=0;null->k=0;null->ch[0]=null->ch[1]=null;
    root=null;
    int n;
    cin>>n;
    while(n--){
        int op=mian();
        if(op==1)ins(mian());
        if(op==2)del(mian());
        if(op==3)printf("%d\n",rnk(mian()));
        if(op==4)printf("%d\n",kth(mian()));
        if(op==5)printf("%d\n",prev(mian()));
        if(op==6)printf("%d\n",succ(mian()));
        // out(),putchar('\n');
        // pout();
    }
//	fprintf(fopen("SBTtime.txt","wb"),"%lfs\n",((double)clock()-t1)/CLOCKS_PER_SEC);
    return 0;
}