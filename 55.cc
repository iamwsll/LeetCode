class Solution {
    public:
        bool canJump(vector<int>& nums) 
        {
            int len_max = 0;
            int n = nums.size();
            for(int i = 0;i<n;i++)
            {
                if(i<=len_max)
                {
                    len_max = max(i+nums[i],len_max);
                    if(len_max>=n-1)return true;
                }
            }   
            return false;
        }
    };