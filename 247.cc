class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) 
        {
            using PII = pair<int,int>;
            unordered_map<int,int> cnt;
            for(auto i:nums)
            {
                cnt[i]++;
            }
            auto f = [](const PII& a,const PII& b)
            {
                return a.second<b.second;
            };
            priority_queue<PII, vector<PII>,decltype(f)> heap;
            for(auto& i:cnt)
            {
                heap.push(i);
            }
    
            vector<int> ans;
            ans.reserve(k+1);
            int times = k;
            while(times--)
            {
                ans.push_back(heap.top().first);
                heap.pop();
            }
            return ans;
        }
    };