class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) 
        {
            return partSelect(nums,0,nums.size()-1,k);
        }
        int partSelect(vector<int>& nums,int l,int r,int k)
        {
            std::cout<<"l = "<<l<<" r = "<<r;
            if(l==r)return nums[l];
            
            int n = nums.size();
            int begin = l;
            int end = r;
            srand(time(0));
            int keyi = rand()%(r-l+1)+l;
            // int keyi = begin;
            swap(nums[keyi],nums[l]);
            std::cout<<" keyi = "<<keyi<<endl;
            while(begin<end)
            {
                while(begin<end&&nums[end]>=nums[l])
                {
                    end--;
                }
                while(begin<end&&nums[begin]<=nums[l])
                {
                    begin++;
                }
                swap(nums[begin],nums[end]);
            }
            swap(nums[l],nums[begin]);
            keyi = begin;
            if(keyi == n-k) return nums[keyi];
            if(keyi < n-k) return partSelect(nums,keyi+1,r,k);
            // else return partSelect(nums,l,keyi-1,k-(n-keyi+1));
            else return partSelect(nums,l,keyi-1,k);
    
        }
    };