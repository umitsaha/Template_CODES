
vector<int> manacher(string s) {
    // pass string #a#b#b#a#
    int n = s.size();
    vector<int> p(n);
    s='%'+s+'@';
    int l = 1, r = -1;
    // center hash even length 
    // center non hash  origin length
    // p is 0 indexed ,rest are 1 index
    for(int i = 1; i <= n; i++) {
        int k;
        if(i>r)k=1;
        else {
            int j=l+r-i;
            k=min(p[j-1],r-i);
        }
        while(i-k>=1 && i+k<=n && s[i - k] == s[i + k])k++;
        if(s[i-k]!=s[i+k])k--;
        p[i-1]=k;  
        if(i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    return p;
}
