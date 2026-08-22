class Solution {
public:
     
 int islandPerimeter(vector<vector<int>>& grid) {



   int n = grid.size();
   int m = grid[0].size();

   int perimeter=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                      if(i-1<0||i-1>=n||j<0||j>=m||grid[i-1][j]==0)
                        perimeter++;

                      if(i+1<0||i+1>=n||j<0||j>=m||grid[i+1][j]==0)
                          perimeter++;

                       if(i<0||i>=n||j-1<0||j-1>=m||grid[i][j-1]==0)
                        perimeter++;

                        if(i<0||i>=n||j+1<0||j+1>=m||grid[i][j+1]==0)
                          perimeter++;
                }
            }    
        }
        return perimeter;
    }
};