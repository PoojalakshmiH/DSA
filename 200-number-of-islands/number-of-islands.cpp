class Solution {
public:


    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>&vis)
   {
     int n=grid.size();
        int m=grid[0].size();
   if(i<0||i>=n||j<0||j>=m||grid[i][j]=='0'||vis[i][j])
   {
        return ;
   }


    vis[i][j]=true;
     
      dfs(grid,i-1,j,vis);
      dfs(grid,i+1,j,vis);
       dfs(grid,i,j-1,vis);
       dfs(grid,i,j+1,vis);
}
    int numIslands(vector<vector<char>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
         int islcount=0;

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
             if(!vis[i][j]&&grid[i][j]=='1') {
                dfs(grid,i,j,vis);
                islcount++;
             }
            }
        }
        
        return islcount;
    }
};