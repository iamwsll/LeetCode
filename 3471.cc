class Solution {
    public:
        int largestInteger(vector<int>& nums, int k) 
        {
            map<int,int,greater<int>> isAlmostMiss;
            int l = 0,r = -1;
            int n = nums.size();
            while(r<n-1)
            {
                r++;
                while(r<n-1&&r-l+1<k)
                {
                    r++;
                }
                if(r-l+1==k)
                {
                    unordered_set<int> unique_nums;
                    for(int i = l;i<=r;i++)
                    {
                        // std::cout<<"i will insert "<<nums[i]<<endl;
                        unique_nums.insert(nums[i]);
                        
                    }
                    for(auto& i: unique_nums)
                    {
                        isAlmostMiss[i]++;
                    }
                    
                    // std::cout<<"end.."<<endl;
                    l++;
                }
            }
            
            for(auto& [x,y]:isAlmostMiss)
            {
                // std::cout<<"x,y = "<<x<<' '<<y<<endl;
                if(y==1)return x;
            }
            return -1;
        }
    };