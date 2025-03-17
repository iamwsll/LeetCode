class Solution {
    public:
        string decodeString(string s) 
        {
            vector<char> v;
            v.resize(100000);
            int top = -1;
            int i = 0;
            while(i<s.size())
            {
                if(('0'<=s[i]&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]=='['))
                {
                    top++;
                    v[top] = s[i];
    
                    i++;
                }
                else //']'
                {
                    top++;
                    v[top] = s[i];
                    int left;
                    for(left = top;left>=0;left--)
                    {
                        if(v[left]=='[')
                        {
                            break;
                        }
                    }
                    int d;
                    for(d = left-1;d>=0;d--)
                    {
                        if(!('0'<=v[d]&&v[d]<='9'))
                        {
                            break;
                        }
                    }
                    string temp;
                    for(int j = left+1;j<top;j++)
                    {
                        temp+=v[j];
                    }
                    int num=v[d+1]-'0';
                    for(int j = d+2;j<left;j++)
                    {
                        num*=10;
                        num+=v[j]-'0';
                    }
                    // std::cout<<" l: "<<left<<" d: "<<d<<" temp:"<<temp<<" num: "<<num<<endl;
                    string ans;
                    while(num--)
                    {
                        ans+=temp;
                    }
                    // std::cout<<ans<<endl;
                    for(int pos = 0;pos<ans.size();pos++)
                    {
                        v[d+1+pos] = ans[pos];
                    }
                    top = d+ans.size();
                    i++;
                }
                    // for(int t = 0;t<20;t++)
                    // {
                    //     cout<<v[t];
                    // }
                    // cout<<"   top: "<<top<<endl;
            }
            string ans;
            for(int pos = 0;pos<=top;pos++)
            {
                ans+=v[pos];
            }
            return ans;
        }
    };