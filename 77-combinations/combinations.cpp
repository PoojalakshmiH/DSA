class Solution {
public:

    void combination(int i,int k,vector<vector<int>> &allsubset,vector<int> &temp,vector<int>&nums)
    {
        if(k==temp.size())
        {
            allsubset.push_back(temp);
            return;
        }
        if(i==nums.size())
        {
           return;  
        }

        temp.push_back(nums[i]);
        combination(i+1,k,allsubset,temp,nums);
        temp.pop_back();
        combination(i+1,k,allsubset,temp,nums);
        
    }
    vector<vector<int>> combine(int n, int k) {
            
            vector<int>nums;
            for(int i=1;i<=n;i++)
            {
                   nums.push_back(i);
            
            }

            vector<vector<int>>allsubset;
            vector<int>temp;
            combination(0,k,allsubset,temp,nums);
            return allsubset;
        
    }
};