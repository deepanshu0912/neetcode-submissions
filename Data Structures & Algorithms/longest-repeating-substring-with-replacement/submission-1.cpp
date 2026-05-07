class Solution {
public:

    bool check(map<char,int> &mp,int k)
    {
        int mx = 0;

        for(auto it : mp)
        {
            mx = max(mx, it.second);
        }

        int total = 0;

        for(auto it : mp)
        {
            total += it.second;
        }

        return (total - mx) <= k;
    }

    int characterReplacement(string s, int k) {

        map<char,int> mp;

        int ans = 0;

        int i = 0;

        for(int j = 0; j < s.size(); j++)
        {
            mp[s[j]]++;

            while(!check(mp,k))
            {
                mp[s[i]]--;

                if(mp[s[i]] == 0)
                    mp.erase(s[i]);

                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};