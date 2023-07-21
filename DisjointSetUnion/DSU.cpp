//827. Making A Large Island -LeetcodeQuestion
class Solution {
public:
    class DSU{
        private:
         vector<int> parent;
         vector<int> s;
        public:
         DSU(int n){
             parent.resize(n);
             s.resize(n);
             for(int i=0;i<n;i++)
                {
                    parent[i] = i;
                    s[i] = 1;
                }
         }
         int find(int a)
         {
             if(a==parent[a])
                return a;
              return parent[a]=find(parent[a]);
         }
         void Union(int a,int b)
         {
             a=find(a);
             b=find(b);
             if(a==b)
                return ;
             if(s[a]<s[b])
                swap(a,b);
             parent[b]=a;
             s[a]+=s[b];
         }
         int getSize(int a){
             return s[a];
         }
         
     };
     int getId(int i,int j,int N)
     {
         return i*N+j;
     }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds((n+1)*(n+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i-1>=0&&grid[i-1][j]==1)
                    {
                        ds.Union(getId(i,j,n),getId(i-1,j,n));
                    }
                    if(j-1>=0&&grid[i][j-1]==1)
                    {
                        ds.Union(getId(i,j,n),getId(i,j-1,n));
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,ds.getSize(getId(i,j,n)));
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    int p1=-1,p2=-1,p3=-1,p4=-1;
                    int s =1;
                    if(i-1>=0&&grid[i-1][j]==1)
                    {
                        p1=ds.find(getId(i-1,j,n));
                        s += ds.getSize(p1);
                    }
                    if(j-1>=0&&grid[i][j-1]==1)
                    {
                        p2=ds.find(getId(i,j-1,n));
                        if(p1!=p2)
                            s += ds.getSize(p2);
                    }
                    if(j+1<n&&grid[i][j+1]==1)
                    {
                        p3=ds.find(getId(i,j+1,n));
                        if(p1!=p3&&p2!=p3)
                            s += ds.getSize(p3);
                    }
                    if(i+1<n&&grid[i+1][j]==1)
                    {
                        p4=ds.find(getId(i+1,j,n));
                        if(p1!=p4&&p2!=p4&&p3!=p4)
                            s += ds.getSize(p4);
                    }
                    
                    ans = max(ans,s);
                }
            }
        }

        return ans;
    }
};