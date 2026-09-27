class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        
        int dr[]={-1,+1,0,0};
        int dc[]={0,0,-1,+1};

        

        while(!pq.empty())
        {
            auto  node =pq.top();
            pq.pop();
            int row=node.second.first;
            int col=node.second.second;
            int diff=node.first;
            

            if(row==n-1&&col==m-1)
            
               return diff;
            
            
            
            for(int k=0;k<4;k++){
                
                int nr=row+dr[k];
                int nc=col+dc[k];

                if(nr>=0&&nc>=0&&nr<n&&nc<m)
                {
                    int neweffort=max(diff,abs(heights[nr][nc]-heights[row][col]));
                    if(neweffort<dist[nr][nc])
                    {
                       pq.push({neweffort,{nr,nc}});
                       dist[nr][nc]=neweffort;
                    }

                }

            }
        }

          return 0;
    }
};