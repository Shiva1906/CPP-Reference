class DSU{
         private:
         vector<int> parent;
         vector<int> s;
         public:
         int groups;
         int maxsize;
         DSU(int n){
             parent.resize(n);
             s.resize(n);
             groups=n;
             maxsize=1;
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
             maxsize = max(maxsize,s[a]);
             groups--;
         }
         
     };