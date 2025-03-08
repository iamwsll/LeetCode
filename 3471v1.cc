class Solution {
    public:
        int largestInteger(vector<int>& nums, int k) 
        {
            int n = nums.size();
            if(k==n)
            {
                return ranges::max(nums);
            }
            if(k==1)
            {
                unordered_map<int, int> cnt;
                for(auto i: nums)
                {
                    cnt[i]++;
                }
    
                int maxVal = -1;
                for(auto& [x,y]:cnt)
                {
                    if(y==1)maxVal = max(maxVal,x);
                }
                return maxVal;
            }
    
            auto f = [&](int pos)
            {
                for(int i = 0;i<n;i++)
                {
                    if(nums[i]==nums[pos]&&(i!=pos))return -1;
                }
                return nums[pos];
            };
            return max(f(0),f(n-1));
        }
    };