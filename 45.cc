class Solution {
    public:
        int jump(vector<int>& nums) 
        {
            int left = 0;
            int n = nums.size();
            // if(n==1)return 0;
            int cnt = 0;
            int r_max = 0;
            // cout<<n<<endl;
            while(r_max<n-1)
            {
                // cout<<left<<' '<<r_max<<endl;
                int i = left;
                int temp = r_max;
                while(i<=temp)
                {
                    // cout<<nums[i]+i<<endl;;
                    r_max = max(r_max,nums[i]+i);
                    i++;
                }
                cnt++;
                left = temp+1;
            }
            return cnt;
        }
    };