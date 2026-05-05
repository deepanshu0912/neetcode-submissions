class Solution {
public:

    bool check(vector<int>& piles, int h, int k)
    {
        int s = 0;
        for(auto i : piles)
        {
            s += (i + k - 1) / k;  // cleaner ceil
        }
        return s <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 0;

        for(auto i : piles)
        {
            high = max(high, i);
        }

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(check(piles, h, mid))
            {
                high = mid - 1;  // try smaller
            }
            else
            {
                low = mid + 1;   // need bigger
            }
        }

        return low;
    }
};