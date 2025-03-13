class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) 
        {
            m = grid.size();
            n = grid[0].size();
            using PII = pair<int,int>;
            queue<PII> q;
            for(int i = 0;i<m;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    if(grid[i][j]==2)
                    {
                        q.push({i,j});
                        st[i][j] = true;
                    }
                }
            }
            int px[] = {1,-1,0,0};
            int py[] = {0,0,-1,1};
            int count = 0;
            while(!q.empty())
            {
                int cnt = q.size();
                while(cnt--)
                {
                    auto [x,y] = q.front();
                    q.pop();
                    for(int i = 0;i<4;i++)
                    {
                        int nowx = px[i]+x;
                        int nowy = py[i]+y;
                        if(nowx>=0&&nowy>=0&&nowx<m&&nowy<n&&!st[nowx][nowy]&&grid[nowx][nowy]==1)
                        {
                            st[nowx][nowy] = true;
                            grid[nowx][nowy]=2;
                            q.push({nowx,nowy});
                        }
                    }
                }
                if(q.empty())break;
                count++;
            }
            for(int i = 0;i<m;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    if(grid[i][j]==1)
                    {
                        return -1;
                    }
                }
            }
            return count;
        }
        int m;
        int n;
        bool st[11][11]{};
    };