class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>time(n,vector<int>(m,-1));

        int dr[]={-1,0,0,+1};
        int dc[]={0,-1,+1,0};
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<sources.size();i++)
        {
            int r=sources[i][0];
            int c=sources[i][1];
            int col=sources[i][2];
            ans[r][c]=col;
            q.push({{r,c},0});
            time[r][c]=0;
        }


        while(!q.empty())
        {
            auto curr = q.front();

          int cr = curr.first.first;
          int cc = curr.first.second;
          int ctime = curr.second;
          int color=ans[cr][cc];
          q.pop();

            for(int i=0;i<4;i++)
            {
                int row=cr+dr[i];
                int col=cc+dc[i];
               

                int newtime=ctime+1;

                if(row>=0&&col>=0&&row<n&&col<m)
                {
                    if(time[row][col]==-1)
                    {
                        time[row][col]=newtime;
                        ans[row][col]=color;
                        q.push({{row,col},newtime});
                    }
                    else{
                        if(time[row][col]==newtime&&ans[row][col]<color)
                        {
                                ans[row][col]=color;
                        }
                    }
                }
            }
        }
        return ans;

    }
};