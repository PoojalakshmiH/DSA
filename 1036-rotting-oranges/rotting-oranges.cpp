class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();

        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;
          
          for(int i=0;i<n;i++)
          {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=true;
                    q.push({{i,j},0});
                }
            }
          }

       while(!q.empty())
       {
        auto node =q.front();
        int i=node.first.first;
        int j=node.first.second;
        int time=node.second;
        ans=max(ans,time);

        q.pop();

        if(i-1>=0&&vis[i-1][j]==false&&grid[i-1][j]==1)
        {
            vis[i-1][j]=true;
            q.push({{i-1,j},time+1});
        }
        if(i+1<n&&vis[i+1][j]==false&&grid[i+1][j]==1)
        {
            vis[i+1][j]=true;
            q.push({{i+1,j},time+1});
        }
        if(j-1>=0&&vis[i][j-1]==false&&grid[i][j-1]==1)
        {
            vis[i][j-1]=true;
            q.push({{i,j-1},time+1});
        }

        if(j+1<m&&vis[i][j+1]==false&&grid[i][j+1]==1)
        {
            vis[i][j+1]=true;
            q.push({{i,j+1},time+1});
        }


       } 

        
       for(int i=0;i<n;i++)
          {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&!vis[i][j])
                {
                    return -1;  
                 
                }
            }
          }

     return ans;
    }
};