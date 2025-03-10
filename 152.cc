class Solution {
    public:
        int maxProduct(vector<int>& nums) 
        {
            int n = nums.size();
            vector<int> max_arr(n);
            vector<int> min_arr(n);
            max_arr[0] = nums[0];
            min_arr[0] = nums[0];
            for(int i = 1;i<n;i++)
            {
                max_arr[i] = max(nums[i],max(min_arr[i-1]*nums[i],max_arr[i-1]*nums[i]));
                min_arr[i] = min(nums[i],min(min_arr[i-1]*nums[i],max_arr[i-1]*nums[i]));
            }
            // for(auto i: max_arr)
            // {
            //     cout<<i<<' '; 
            // }
            return ranges::max(max_arr);
        }
    };