class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int ma=nums[0],start=nums[0];
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
            mp[nums[i]]++;
            ma=max(ma,nums[i]);
        }
        vector<int> ans;
        ans.push_back(pq.top());
        int i=k;
        while(i<nums.size())
        {
            int re=nums[i-k];
            mp[nums[i-k]]--;
            if (mp[nums[i-k]] == 0) {
    mp.erase(nums[i-k]);
            }
            pq.push(nums[i]);
            mp[nums[i]]++;
            while(mp.find(pq.top())==mp.end()){pq.pop();}
            ans.push_back(pq.top());
            i++;
        }
        return ans;

    }
};
