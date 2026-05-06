class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, vector<bool>& used)
    {
        if(curr.size() == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            // skip already used elements
            if(used[i]) continue;

            // skip duplicates
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums, ans, curr, used);

            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // IMPORTANT

        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        solve(nums, ans, curr, used);
        return ans;
    }
};