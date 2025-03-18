class Solution {
    public:
        string decodeString(string s) 
        {
            //方便处理,我们可以想象整个s是被一个最外层的[]包裹的
            //ans就存储的是[之后的字符串
            stack<int> nums;
            stack<string> st;
            int num =0;
            string ans;
            int n = s.size();
            for(int i = 0;i<n;i++)
            {
                if(isdigit(s[i]))
                {
                    num*=10;
                    num+=s[i]-'0';
                }
                else if(isalpha(s[i]))
                {
                    ans+=s[i];
                }
                else if(s[i]=='[')
                {
                    nums.push(num);
                    num = 0;
                    st.push(ans);
                    ans = "";
                }
                else if(s[i]==']')
                {
                    string temp;
                    int cnt = nums.top();
                    nums.pop();
                    while(cnt--)
                    {
                        temp+=ans;
                    }
                    ans = st.top();
                    st.pop();
                    ans+=temp;
                }
            }
            return ans;    
        }
    };