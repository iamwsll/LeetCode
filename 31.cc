class Solution {
    public:
        void nextPermutation(vector<int>& nums) 
        {
            int i = -1;
            int j = 0x3f3f3f3f;
            int n = nums.size();
            if(n==1)return ;
            for(int pos = n-1;pos>=1;--pos)
            {
                if(nums[pos-1]<nums[pos])
                {
                    i = pos-1;
                    break;
                }
            }
            std::cout<<i<<endl;
            if(i==-1)
            {
                reverse(nums.begin(),nums.end());
                return;
            }
            
            for(int pos = n-1;pos>=i;--pos)
            {
                if(nums[pos]>nums[i])
                {
                    j = pos;
                    break;
                }
            }
            swap(nums[i],nums[j]);
            std::cout<<j<<endl;
            reverse(nums.begin()+i+1,nums.end());
    
            return;
        }
        
    };