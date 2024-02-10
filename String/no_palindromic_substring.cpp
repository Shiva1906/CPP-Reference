class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans=0;
        int l ,r;
        for(int i =0;i<n;i++){
            l=i;
            r=i;
            while(l>=0&&r<n&&s[l]==s[r]){
                ans++;
                l--;
                r++;
            }
            l =i;
            r=i+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};