class Solution {
public:
    void solve(int idx, vector<vector<string>>&res,vector<string>&path,string s)
    {
        if(idx==s.size())
        {
            res.push_back(path);
            return;
        }
        for(int i=idx;i<s.size();i++)
        {
            if(palindrome(idx,i,s))
            {
                path.push_back(s.substr(idx,i-idx+1));
                solve(i+1,res,path,s);
                path.pop_back();
            }
        }
    }




   bool palindrome(int start,int end,string s)
    {
       while(start<=end)
       {
        if(s[start++]!=s[end--])
        {
            return false;
        }      
       }
       return true;
    }
   
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        solve(0,res,path,s);
        return res;

    }
};