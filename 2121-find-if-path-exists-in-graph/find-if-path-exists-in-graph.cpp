class Solution {
public:
    
    bool dfs(int n, vector<vector<int>>& adj, int src, int destination,vector<bool>&vis)
    {
        vis[src]=true;
           
           for(int v:adj[src])
           {
             if(v==destination)
             {
                return true;
             }
             if(!vis[v])
             {
                if(dfs(n,adj,v,destination,vis))
               return true;
            }
           }
        
        return false;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>vis(n,false);
        vector<vector<int>> adj(n);
      if(source == destination)
        return true;

        for(auto edge: edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

   
       if(dfs(n,adj,source,destination,vis))
         return true;

       return false;
    }
   
};