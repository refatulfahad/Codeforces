#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>vertex[N];
int par[N];
int nd,sz[N];
bool visit_centroid[N];

void dfs(int node,int p) {
    nd++;
    sz[node]=1;
    for(int v:vertex[node]) {
        if(v!=p&&!visit_centroid[v]) {
            dfs(v,node);
            sz[node]+=sz[v];
        }
    }
}

int centroid(int node,int p) {
    for(int v:vertex[node]) {
        if(v!=p&&!visit_centroid[v]&&sz[v]>nd/2) {
            return centroid(v,node);
        }
    }
    return node;
}
void decompose(int node,int p) {
    nd=0;
    dfs(node,0);
    int center=centroid(node,0);
    visit_centroid[center]=true;
    if(p==0) {
        par[center]=65;
    } else {

        par[center]=par[p]+1;
    }
    for(int v:vertex[center]) {
        if(!visit_centroid[v]) {
            decompose(v,center);
        }
    }
}
int main() {
    int n,x,y;
    scanf("%d",&n);
    for(int i=1; i<n; i++) {
        scanf("%d %d",&x,&y);
        vertex[x].push_back(y);
        vertex[y].push_back(x);
    }
    decompose(1,0);

    for(int i=1;i<=n;i++){
        char ch=par[i];
        printf("%c",ch);
        if(i!=n)cout<<" ";
    }
    return 0;
}
