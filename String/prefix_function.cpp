// max pref match
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// match pref
//v-> pref function vect
ll baal=j;
if(baal){
    // lst matc
    baal=v[baal-1];
    // until match
    while(baal>0 && 'A'+l!=s[baal]){
        baal=v[baal-1];
    }
    baal+=(s[baal]=='A'+l);
}
