class Solution {
public:

    void sum(vector<int>& nums, int target, vector<vector<int>>& ans, int i, vector<int>& c)
    {
        if(target == 0)
        {
            ans.push_back(c);
            return;
        }

        if(i == nums.size() || target < 0)
            return;

        // skip
        sum(nums, target, ans, i + 1, c);

        // take
        c.push_back(nums[i]);
        sum(nums, target - nums[i], ans, i, c);  // stay at i
        c.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> c;
        vector<vector<int>> ans;
        sum(nums, target, ans, 0, c);
        return ans;
    }
};