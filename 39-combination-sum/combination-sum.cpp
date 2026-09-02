class Solution {
public:

    void findsubset(int i,vector<int>&ds, vector<vector<int>>&allsubset,vector<int>&arr, int target)
    {
         if(target==0)
            {
                allsubset.push_back(ds);
                return;
            }
        if(i==arr.size())
        {
            return;
        }
        if(arr[i]<=target)
        {
            ds.push_back(arr[i]);
            findsubset(i,ds,allsubset,arr,target-arr[i]);
            ds.pop_back();
           
        }
         findsubset(i+1,ds,allsubset,arr,target);
    }

    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>allsubset;
        vector<int>ds;

        findsubset(0,ds,allsubset,candidates,target);
        return allsubset;
    }
};