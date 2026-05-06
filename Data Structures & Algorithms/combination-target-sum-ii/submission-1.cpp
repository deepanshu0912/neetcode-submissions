class Solution {
public:
    void solve(vector<int>& nums, int target, vector<vector<int>>& ans, int i, vector<int>& curr)
    {
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }

        for(int j = i; j < nums.size(); j++)
        {
            // skip duplicates
            if(j > i && nums[j] == nums[j - 1]) continue;

            // pruning
            if(nums[j] > target) break;

            curr.push_back(nums[j]);
            solve(nums, target - nums[j], ans, j + 1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // IMPORTANT

        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, target, ans, 0, curr);
        return ans;
    }
};