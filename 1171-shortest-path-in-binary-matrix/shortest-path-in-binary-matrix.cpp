class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int n=grid.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        
        if(grid[0][0]!=0 ||grid[n-1][n-1]!=0)
        {
            return  -1;
        }
        q.push({{0,0},1});
        vis[0][0]=true;

        int dr[]={-1,+1,0,0,-1,-1,+1,+1};
        int dc[]={0,0,-1,+1,-1,+1,-1,+1};
        

        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int i=node.first.first;
            int j=node.first.second; 
            int dist=node.second;
            
            if(i==n-1 && j==n-1)
            {
                return dist;
            }

            for(int k=0;k<8;k++)
            {
               int  ni=i+dr[k];
               int  nj=j+dc[k];
                if(ni>=0&&nj>=0&&ni<n&&nj<n&&vis[ni][nj]==false&&grid[ni][nj]==0)
                {
                    q.push({{ni,nj},dist+1});
                    vis[ni][nj]=true;
                }
            }
            

        }

       return -1;
    }
};