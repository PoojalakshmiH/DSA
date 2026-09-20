class Solution {
public:

    void dfs(int src ,int source,vector<int>&vis,vector<vector<int>>&ans,vector<vector<int>>&adj)
    {
        vis[src]=true;
        

        for(int v:adj[src])
        {
            if(!vis[v])
            {
                ans[v].push_back(source);
               dfs(v,source,vis,ans,adj);
            }
        }
    }
   
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }

        vector<vector<int>>ans(n);

        for(int i=0;i<n;i++)
        {
            vector<int>visited(n,false);
            dfs(i,i,visited,ans,adj);
        }

        for(int i = 0; i < n; i++)
        {
          sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};