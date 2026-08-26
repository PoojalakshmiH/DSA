class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     vector<int>dist(n+1,INT_MAX);
     vector<vector<pair<int,int>>>adj(n+1);
     

     for(int i=0;i<times.size();i++)
     {
        int u=times[i][0];
        int v=times[i][1];
        int w=times[i][2];

        adj[u].push_back({v,w});
     }

     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

       dist[k]=0;
       pq.push({0,k});


     while(!pq.empty())
     {
        auto node =pq.top();
        int u =node.second; 
        pq.pop();
          for( auto e: adj[u])
          {
            int v = e.first;
          int wt = e.second;
            if(dist[v]>dist[u]+wt)
            {
                dist[v]=dist[u]+wt;
                pq.push({dist[v],v});
            }
          }
     }



     
     int ans=0;

     for(int i=1;i<=n;i++)
     {
        if(dist[i]==INT_MAX)
            return -1;
        else
        {
            ans=max(ans,dist[i]);
        }

     }
       

      return ans;




    }
};