#include<bits/stdc++.h>
using namespace std;
int N=1e5+1;
vector<int> adj[100000];
int n,m;
vector<vector<int>> edges;
bool vis[100000]={0};
 std::vector<int> par(N,0);
std::vector<int> depth(N,0);


void dfs(int curr,int parr){
    par[curr]=parr;
    depth[curr]=depth[parr]+1;
    for(auto it:adj[curr]){
        if(it!=parr){
            dfs(it,curr);
        }
    }
}
void lca(int x,int y){
   //implementing of x>y
    dfs(1,0);
    for(int i=1;i<=n;++i){
        cout<<i<<" "<<depth[i]<<" "<<par[i]<<endl;
    }
    if(depth[x]<depth[y]) swap(x,y);
    int diff=depth[x]-depth[y];
    cout<<diff<<endl;
    while(diff--){
        x=par[x];
    }

    while(x!=y){
        x=par[x];
        y=par[y];
    }

    cout<<x;

    
}

int main() {
  
    cin >> n>>m;

    
    for (int i = 1; i <=m; ++i) {
        vector<int> tmp(2);
        cin >> tmp[0];
        cin >> tmp[1];
        edges.push_back(tmp);
    }
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
          adj[it[1]].push_back(it[0]);
    }
    
 

    lca(6,3);
 
   
    return 0;
}
