class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        
        vector<vector<pair<int,int>>> adj(n);


        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
          adj[u].push_back({v,wt});
        }

        vector<int>dist(n,INT_MAX);

        queue<pair<int,pair<int,int>>>q;
        dist[src]=0;
        q.push({src,{0,-1}});

     while(!q.empty()){
        auto edge =q.front();

        int node=edge.first;
        int cost=edge.second.first;
        int stop=edge.second.second;
        q.pop();
 
      for(auto neigh:adj[node])
      {
        int v=neigh.first;
        int wt=neigh.second;
        if(dist[v]>cost+wt && stop+1<=k)
        {
            dist[v]=cost+wt;
            q.push({v,{dist[v],stop+1}});
        }
      }
    }


   if(dist[dst]==INT_MAX){
     return -1;
    }
    return dist[dst];
 }
};