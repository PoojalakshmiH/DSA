class Solution {
public:
    void findsubset(int i,vector<int>& nums, vector<int>&ans,vector<vector<int>>&allsubset)
    {
        if(i==nums.size())
        {
            allsubset.push_back(ans);
            return;
        }

        ans.push_back(nums[i]);
        findsubset(i+1,nums,ans,allsubset);
        
        ans.pop_back();

        int idx=i+1;

        while(idx<nums.size()&&nums[idx-1]==nums[idx])
        {
            idx++;
        }
         
        findsubset(idx,nums,ans,allsubset);


    }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>>allsubset;
        vector<int>ans;
        findsubset(0,nums,ans,allsubset);
        return allsubset;

    }
};