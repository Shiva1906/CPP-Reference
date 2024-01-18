vector<int> computeLPSArray(string pat){
    int n = pat.length();
    vector<int> lps(n,0);
    int i = 1;
    lps[0] =0;
    int len =0;
    while(i<n){
        if(pat[i]== pat[len]){
            lps[i] = len+1;
            len++;
            i++;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i] =0;
                i++;
            }
        }
    }
    return lps;
}
vector<int> KMP(string text, string pattern) {
    vector<int> lps = computeLPSArray(pattern);
    int i =0,j=0;
    int n = text.length();
    vector<int> ans;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }else{
            if(j!=0)
              j=lps[j-1];
            else
              i++; 
        }
        if(j==pattern.size()){
            ans.push_back(i-j);
            j = lps[j-1];
        }
    }
    return ans;
}
