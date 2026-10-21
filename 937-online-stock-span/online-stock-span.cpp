class StockSpanner {
public:
     stack<pair<int,int>>s;
        int index=-1;
    StockSpanner() {
      index=-1;
        

    }
    
    int next(int price) {

        index=index+1;

        while(!s.empty()&& s.top().first<=price)
        {
            s.pop();
        }

        int ans =index-( s.empty()?-1:s.top().second);

        s.push({price,index});

        return ans;
        
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */