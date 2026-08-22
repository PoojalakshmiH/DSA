class Solution {
public:


    void dfs(vector<vector<int>>& isConnected,int i,vector<bool>&vis,int n)
   {
       vis[i]=true;

       for(int j=0;j<n;j++)
       {
        if(isConnected[i][j]==1 && !vis[j])
        {
             dfs(isConnected,j,vis,n);
        }
       }

   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int provinces=0;

        vector<bool>vis(n,false);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(isConnected,i,vis,n);
                provinces++;
            }
        }
        return provinces;
    }
};