class Solution {
public:
    int manhattandistance(int p1,int p2 ,vector<vector<int>>& points)
    
    {
        return abs(points[p1][0]-points[p2][0])+
        abs(points[p1][1]-points[p2][1]);
     }
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n=points.size();
        vector<bool>mst(n,false);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        int mincost=0;
        pq.push({0,0});

        while(!pq.empty())
        {
            auto p=pq.top();
            int wt=p.first;
            int node=p.second;

            pq.pop();

            if(mst[node])  continue;

            mst[node]=true;
            mincost+=wt;

            for(int i=0;i<n;i++)
            {
                if(!mst[i])
                {
                   int  edgewt=manhattandistance(node,i,points);
                    pq.push({edgewt,i});
                }
            }
            
        }
        return mincost;

    }
};