class Solution {
public:

     bool dfs(vector<vector<int>>& adj,vector<int>&color,int col,int i)
     {
        color[i]=col;


        for(int v:adj[i])
        {
            if(color[v]==-1)
            {
                if(dfs(adj,color,!col,v) ==false)
                {
                    return false;
                }
            }
            else if(color[v]==col)
            {
                return false;
            }
        }
        return true;
     }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        

        vector<vector<int>>adj(n+1);

        for(int i=0;i<dislikes.size();i++)
        {
            int u=dislikes[i][0];
            int v=dislikes[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>color(n+1,-1);

        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(adj,color,0,i)==false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};