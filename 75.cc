class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int p0 = 0,p1 = 0;//p0 p1 指向的其实是"一排0/1的下一个位置"
            for(int i = 0;i<n;i++)
            {
                if(nums[i]==1)
                {
                    swap(nums[i],nums[p1]);
                    p1++;
                }
                else if(nums[i]==0)
                {
                    swap(nums[i],nums[p0]);
                    if(p0<p1)
                    {
                        swap(nums[i],nums[p1]);
                    }
                    p0++;
                    p1++;
                }
            }
        }
    };