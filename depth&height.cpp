#include<bits/stdc++.h>
using namespace std;


void dfs(std::vector<int> adj[],int node,int cnt,bool vis[],std::vector<int> &ans){
        ans[node]=cnt;
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(adj,it,cnt+1,vis,ans);
            }
        }
}

std::vector<int> DepthT(int n, vector<vector<int>> edges){ //depth
    std::vector<int> adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int root=1;
    std::vector<int> ans(n+1,0);
    bool vis[n+1]={0};
    dfs(adj,root,0,vis,ans);
    for(int i=1;i<=n;++i){
        cout<<i<<" "<<ans[i]<<endl;
    }
    return ans;

}
std::vector<int> HT(int n, vector<int> depth){ //height
   std::vector<int> height(n);
   int maxD=0;
   for(auto it:depth){
    maxD=max(maxD,it);
   }
   for(int i=1;i<=n;++i){
    height[i]=maxD-depth[i];
   }
    for(int i=1;i<=n;++i){
    cout<<i<<" "<<height[i]<<endl;
   }

   return height;

}

int main() {
    int n,m;
    cin >> n>>m;

    vector<vector<int>> edges;
    for (int i = 1; i <=m; ++i) {
        vector<int> tmp(2);
        cin >> tmp[0];
        cin >> tmp[1];
        edges.push_back(tmp);
    }
    
  vector<int> ans1=DepthT(n,edges);
  vector<int> ans2=HT(n,ans1);


    
 
   
    return 0;
}
