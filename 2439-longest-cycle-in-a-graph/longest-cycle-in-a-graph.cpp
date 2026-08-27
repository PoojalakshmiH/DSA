class Solution {
public:
     int ans=-1;
             

    void dfs(int u,vector<bool>&vis,vector<int>&edges,vector<bool>&recpath,vector<int>&depth,int d)
    {   
        vis[u]=true;
        recpath[u]=true;
        depth[u]=d;
        int v=edges[u];

        if(v!=-1)
        {
            if(!vis[v])
            {
                 dfs(v,vis,edges,recpath,depth,d+1);
            }
            else if(recpath[v]==true)
            {
                 int cyclen=depth[u]-depth[v]+1;
                 ans=max(ans,cyclen);
            }
        }
        recpath[u]=false;
        
    }



    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        
        vector<bool>vis(n,false);
        vector<bool>recpath(n,false);
        vector<int>depth(n,0);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,edges,recpath,depth,0);
            }
        }

        return ans;
    }  
   
};