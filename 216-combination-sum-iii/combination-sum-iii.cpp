class Solution {
public:
    
    void findsubsets(int k,int i, int sum,vector<vector<int>> &allsubsets,vector<int> &ds,vector<int>&nums)
    {
        if(i==nums.size())
        {
            if(sum==0 && ds.size()==k)
            {
                allsubsets.push_back(ds);
                
            }
            return;
        }

        ds.push_back(nums[i]);
        findsubsets(k,i+1,sum-nums[i],allsubsets,ds,nums);
        ds.pop_back();
         findsubsets(k,i+1,sum,allsubsets,ds,nums);
    }

   
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>allsubsets;
        vector<int>ds;
        vector<int>nums;
        for(int i=1;i<=9;i++)
        {
            nums.push_back(i);
        }

        findsubsets(k,0,n,allsubsets,ds,nums);
        return allsubsets;
    }
};