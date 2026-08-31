class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<double>succpro(n,0.0);
        priority_queue<pair<double,int>>pq;
        

        vector<vector<pair<int,double>>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succProb[i];


            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        
        succpro[start_node]=1.0;
        pq.push({1.0, start_node});


        while(!pq.empty())
        {
            auto node = pq.top();

            double prob=node.first;
            int u=node.second;
            pq.pop();

            if(u==end_node) return succpro[end_node];

            for(auto it :adj[u])
            {
                int v= it.first;
                double wt =it.second;

                if(succpro[v]<succpro[u]*wt)
                {
                    succpro[v]=succpro[u]*wt;
                    pq.push({succpro[v],v});
                }
            }
        }
        return 0.0;

    }
};