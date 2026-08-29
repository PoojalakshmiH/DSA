class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<bool>>vis(n,vector<bool>(m,0));

        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {   vis[i][j]=true;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty())
        {
            auto node =q.front();
            int i= node.first.first;
            int j=node.first.second;
            int d=node.second;

            dist[i][j]=d;
            q.pop();
            
            if(i-1>=0 && vis[i-1][j]==false )
            {    vis[i-1][j]=true;
                q.push({{i-1,j},d+1});
            }

             
            if(i+1<n && vis[i+1][j]==false )
            {    vis[i+1][j]=true;
                q.push({{i+1,j},d+1});
            }

             if(j-1>=0 && vis[i][j-1]==false )
            {    vis[i][j-1]=true;
                q.push({{i,j-1},d+1});
            }

             if(j+1<m && vis[i][j+1]==false )
            {    vis[i][j+1]=true;
                q.push({{i,j+1},d+1});
            }

        }
        return  dist;
    }
};