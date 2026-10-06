class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            
        }
          int mod= (int)(1e9+7);
           vector<long long> dist(n, LLONG_MAX);
            vector<int> ways(n, 0);

          priority_queue<
          pair<long long,int>,
          vector<pair<long long,int>>,
          greater<pair<long long,int>>
          > pq;

          dist[0] = 0;
          ways[0] = 1;

          pq.push({0, 0});

          while(!pq.empty())
        {
           long long dis = pq.top().first;
           int node = pq.top().second;

           pq.pop();

    

         for(auto it : adj[node])
        {
            int v = it.first;
             int wt = it.second;

        if(dist[v] > dis + wt)
        {
            dist[v] = dis + wt;

            pq.push({dist[v], v});

            ways[v] = ways[node];
        }
        else if(dist[v] == dis + wt)
        {
            ways[v] = (ways[v] + ways[node]) % mod;
        }
      }
    }
        return ways[n-1]%mod;

    }
};