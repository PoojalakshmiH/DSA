class Solution {
public:
  
  
      void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis,int &countarea)
      {
         
        int n=grid.size();
        int m=grid[0].size();
         if(i<0||i>=n||j<0||j>=m||grid[i][j]==0||vis[i][j])
        {
             return ;
        }

        countarea++;
        vis[i][j]=true;
     
      dfs(grid,i-1,j,vis, countarea);
      dfs(grid,i+1,j,vis,countarea);
       dfs(grid,i,j-1,vis,countarea);
       dfs(grid,i,j+1,vis,countarea);
       
     
      }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int maxarea=0;
        

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1&&!vis[i][j])
                {
                     int countarea =0;
                    dfs(grid,i,j,vis,countarea);
                    maxarea = max(maxarea, countarea);
                }
            }
        }
       return maxarea; 
    }
};