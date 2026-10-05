class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
     int n=temperatures.size();
     vector<int>ans(n,0);
     stack<pair<int,int>>s;

     for(int i=n-1;i>=0;i--)
     {
        while(!s.empty()&&s.top().second<=temperatures[i])
        {
            s.pop();
        }

        if(s.empty())
        {
            ans[i]=0;
        }
        else
        {   int idx=s.top().first;
            
            ans[i]=idx-i;
        }
        s.push({i,temperatures[i]});
     }
     return ans;
        
    }
};