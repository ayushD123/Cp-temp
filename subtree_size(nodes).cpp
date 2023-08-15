//program to calculate number of subtree nodes for each vertex
//    1
//  3   2
//     4  5
// Here 1 has 5(including 1 itself) subnodes and 3 have 1,2 hve 2 and 5,4 hve 1
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int node, bool vis[], int subtree_size[]) {
    vis[node] = true;
    subtree_size[node] = 1;
    
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(adj, neighbor, vis, subtree_size);
            subtree_size[node] += subtree_size[neighbor];
        }
    }
}

void countSubtreeNodes(int n, vector<vector<int>>& edges, vector<int>& queries) {
    vector<int> ans;
    vector<int> adj[n + 1];
    
    for (vector<int>& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
    int subtree_size[n + 1] = {0};
bool vis[n + 1] = {false};
    
            dfs(adj, 1, vis, subtree_size);
        

      
    
    
    for(int i=1;i<=n;++i){
        cout<<subtree_size[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges;
    for (int i = 1; i < n; ++i) {
        vector<int> tmp(2);
        cin >> tmp[0];
        cin >> tmp[1];
        edges.push_back(tmp);
    }
    
    vector<int> queries;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        queries.push_back(x);
    }
    
   countSubtreeNodes(n, edges, queries);
   
    return 0;
}

