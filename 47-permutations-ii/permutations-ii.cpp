class Solution {
public:


   void solve(vector<vector<int>> &ans,vector<int>& nums,int idx)
   {
    if(idx==nums.size()){
        ans.push_back(nums);
        return;
    }

    unordered_set<int>used;

    for(int i=idx;i<nums.size();i++)
    {
        if(used.count(nums[i]))
        {
            continue;
        }

        used.insert(nums[i]);

        swap(nums[idx],nums[i]);

        solve(ans,nums,idx+1);

        swap(nums[idx],nums[i]);

    }
   }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(ans,nums,0);
        return ans;
    }
};