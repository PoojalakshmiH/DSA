class Solution {
public:

   bool dfs( int i,vector<bool>&vis,vector<bool>&recpath,vector<bool>&check,vector<vector<int>>& graph)
   {
    vis[i]=true;
     recpath[i]=true;
     check[i]=0;

     for(int v:graph[i])
     {
        if(!vis[v])
        {
            if(dfs(v,vis,recpath,check,graph))
            {
                check[v]=0;
                return  true;
            }
        }
        else if(recpath[v])
        {   check[v]=0;
            return true;
        }
     }

     check[i]=1;
     recpath[i]=false;
     return false;
   }



    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n=graph.size();
         vector<bool>vis(n,false);
         vector<bool>recpath(n,false);
         vector<bool>check(n,false);
         vector<int>safe;

         for(int i=0;i<n;i++)
         {
            if(!vis[i])
            {
                dfs(i,vis,recpath,check,graph);
            }
         }

         for(int i=0;i<n;i++)
         {
            if(check[i]==1)
            {
                safe.push_back(i);
            }
         }
         return safe;

    }
};