class Solution {
public:
    void sol(vector<int>& nums,int i,vector<vector<int>> & ans,vector<int> a)
    {
        if(i>=nums.size()){ans.push_back(a);return;}
        sol(nums,i+1,ans,a);
        a.push_back(nums[i]);
        sol(nums,i+1,ans,a);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        sol(nums,0,ans,a);
        return ans;
    }
};
