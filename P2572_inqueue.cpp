#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
    int val;//1的个数
    int lef[2];//左起连续01
    int rit[2];//右起连续01
    int mid[2];//最长连续01
    int tagval;//-1->不作操作， | 0->全0 | 1->全1 |
    bool tagx;//xor标签
}sgt[400010];
int a[100010];//原始值
inline int ls (int x){
    return x<<1;
}
inline int rs(int x){
    return x<<1|1;
}
inline void update(int root,int l,int r){
    int mid = (l+r)>>1;
    for(int i=0;i<=1;i++){
        sgt[root].lef[i]=sgt[ls(root)].lef[i];
        sgt[root].rit[i]=sgt[rs(root)].rit[i];
        sgt[root].mid[i]=sgt[ls(root)].rit[i]+sgt[rs(root)].lef[i];
        if(i==1){
        //left
            if(sgt[ls(root)].val==(mid-l+1)){
                sgt[root].lef[i]+=sgt[rs(root)].lef[i];
            }
        //right
            if(sgt[rs(root)].val==(r-mid)){
                sgt[root].rit[i]+=sgt[ls(root)].rit[i];
            }
        }
        if(i==0){
        //left
            if(sgt[ls(root)].val==0){
                sgt[root].lef[i]+=sgt[rs(root)].lef[i];
            }
        //right
            if(sgt[rs(root)].val==0){
                sgt[root].rit[i]+=sgt[ls(root)].rit[i];
            }
        }
        sgt[root].mid[i]=max(sgt[root].mid[i],max(sgt[ls(root)].mid[i],sgt[rs(root)].mid[i]));
    }
    sgt[root].val=sgt[ls(root)].val+sgt[rs(root)].val;
    return ;
}
void build(int root,int l,int r){
    sgt[root].tagval=-1;
    if(l==r){
        if(a[l]==0){
            sgt[root].val=0;
            sgt[root].lef[0]=sgt[root].rit[0]=sgt[root].mid[0]=1;
            sgt[root].lef[1]=sgt[root].rit[1]=sgt[root].mid[1]=0;
        }
        if(a[l]==1){
            sgt[root].val=1;
            sgt[root].lef[0]=sgt[root].rit[0]=sgt[root].mid[0]=0;
            sgt[root].lef[1]=sgt[root].rit[1]=sgt[root].mid[1]=1;
        }
        return ;
    }
    int mid = (l+r)>>1;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    update(root,l,r);
    return ;
}
void pushdown(int root,int l,int r){
    int mid = (l+r)>>1;
    if(sgt[root].tagval>=0){
        sgt[root].tagx=false;
        sgt[ls(root)].val=sgt[root].tagval*(mid-l+1);
        sgt[rs(root)].val=sgt[root].tagval*(r-mid);
        sgt[ls(root)].tagval=sgt[rs(root)].tagval=sgt[root].tagval;
        sgt[ls(root)].tagx=sgt[rs(root)].tagx=false;
        sgt[ls(root)].mid[sgt[root].tagval]=sgt[ls(root)].lef[sgt[root].tagval]=sgt[ls(root)].rit[sgt[root].tagval]=(mid-l+1);
        sgt[rs(root)].mid[sgt[root].tagval]=sgt[rs(root)].lef[sgt[root].tagval]=sgt[rs(root)].rit[sgt[root].tagval]=(r-mid);
        sgt[ls(root)].mid[sgt[root].tagval^1]=sgt[ls(root)].lef[sgt[root].tagval^1]=sgt[ls(root)].rit[sgt[root].tagval^1]=0;
        sgt[rs(root)].mid[sgt[root].tagval^1]=sgt[rs(root)].lef[sgt[root].tagval^1]=sgt[rs(root)].rit[sgt[root].tagval^1]=0;
        sgt[root].tagval=-1;
    }
    if(sgt[root].tagx){
        sgt[ls(root)].val=(mid-l+1)-sgt[ls(root)].val;
        sgt[rs(root)].val=(r-mid)-sgt[rs(root)].val;
        if(sgt[ls(root)].tagval!=-1){
            sgt[ls(root)].tagval^=1;
        }
        else {
            sgt[ls(root)].tagx^=1;
        }
        if(sgt[rs(root)].tagval!=-1){
            sgt[rs(root)].tagval^=1;
        }
        else { 
            sgt[rs(root)].tagx^=1;
        }
        swap(sgt[ls(root)].lef[0],sgt[ls(root)].lef[1]);
        swap(sgt[ls(root)].mid[0],sgt[ls(root)].mid[1]);
        swap(sgt[ls(root)].rit[0],sgt[ls(root)].rit[1]);
        swap(sgt[rs(root)].lef[0],sgt[rs(root)].lef[1]);
        swap(sgt[rs(root)].mid[0],sgt[rs(root)].mid[1]);
        swap(sgt[rs(root)].rit[0],sgt[rs(root)].rit[1]);
        sgt[root].tagx=false;
    }
    return ;
}
void change(int root,int nl,int nr,int l,int r,int k){
    pushdown(root,nl,nr);
    if(l>nr||nl>r){
        return ;
    }
    if(nl>=l&&r>=nr){
        sgt[root].val=k*(nr-nl+1);
        sgt[root].tagval=k;
        sgt[root].lef[k]=sgt[root].rit[k]=sgt[root].mid[k]=(nr-nl+1);
        sgt[root].lef[k^1]=sgt[root].rit[k^1]=sgt[root].mid[k^1]=0;
        return ;
    }
    int mid = (nl+nr)>>1;
    change(ls(root),nl,mid,l,r,k);
    change(rs(root),mid+1,nr,l,r,k);
    update(root,nl,nr);
    return ;
}
void Xor(int root,int nl,int nr,int l,int r){
    pushdown(root,nl,nr);
    if(l>nr||nl>r){
        return ;
    }
    if(nl>=l&&r>=nr){
        sgt[root].val=(nr-nl+1)-sgt[root].val;
        if(sgt[root].tagx){
            sgt[root].tagx=false;
        }
        else {
            sgt[root].tagx=true;
        }
        swap(sgt[root].lef[0],sgt[root].lef[1]);
        swap(sgt[root].mid[0],sgt[root].mid[1]);
        swap(sgt[root].rit[0],sgt[root].rit[1]);
        return ;
    }
    int mid = (nl+nr)>>1;
    Xor(ls(root),nl,mid,l,r);
    Xor(rs(root),mid+1,nr,l,r);
    update(root,nl,nr);
    return ;
}
int querytot(int root,int nl,int nr,int l,int r){
    if(l>nr||nl>r){
        return 0;
    }
    if(nl>=l&&r>=nr){
        return sgt[root].val;
    }
    pushdown(root,nl,nr);
    int mid = (nl+nr)>>1;
    return querytot(ls(root),nl,mid,l,r)+querytot(rs(root),mid+1,nr,l,r);
}
Node queryrow(int root,int nl,int nr,int l,int r){
    pushdown(root,nl,nr);
    if(nl>=l&&r>=nr){
        return sgt[root];
    }
    int mid = (nl+nr)>>1;
    if(mid<l){
        return queryrow(rs(root),mid+1,nr,l,r);
    }
    else if(mid>=r){
        return queryrow(ls(root),nl,mid,l,r);
    }
    else {
        Node ans;
        Node Lef=queryrow(ls(root),nl,mid,l,r);
        Node Rit=queryrow(rs(root),mid+1,nr,l,r);
        for(int i=0;i<=1;i++){
            ans.lef[i]=Lef.lef[i];
            ans.rit[i]=Rit.rit[i];
            if(i==1){
                if(Lef.val==(mid-nl+1)){
                    ans.lef[i]+=Rit.lef[i];
                }
                if(Rit.val==(nr-mid)){
                    ans.rit[i]+=Lef.rit[i];
                }
            }
            if(i==0){
                if(Lef.val==0){
                    ans.lef[i]+=Rit.lef[i];
                }
                if(Rit.val==0){
                    ans.rit[i]+=Lef.rit[i];
                }
            }
            ans.mid[i]=max(max(Lef.rit[i]+Rit.lef[i],Lef.mid[i]),Rit.mid[i]);
        }
        return ans;
    }
}
int n,m;
int main(){
    freopen("testdata.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    int typ,l,r;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&typ,&l,&r);
        l++,r++;
        if(typ==0){
            change(1,1,n,l,r,0);
        }
        if(typ==1){
            change(1,1,n,l,r,1);
        }
        if(typ==2){
            Xor(1,1,n,l,r);
        }
        if(typ==3){
            printf("%d\n",querytot(1,1,n,l,r));
        }
        if(typ==4){
            printf("%d\n",queryrow(1,1,n,l,r).mid[1]);
        }
    }
    return 0;
}