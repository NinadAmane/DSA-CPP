class Solution {
public:
    int mod = 1e9 + 7;
    int dp[2001];
    vector<int> prev;

    int subseq(int n){
        if(n == 0){
            return 1;
        }

        if(dp[n] != -1) return dp[n];

        int total =  (subseq(n-1) % mod * 2) % mod;
        if(prev[n] != 0){
            int duplicates = subseq(prev[n] - 1);
            total = (total - duplicates + mod) % mod;
        }

        return dp[n] = total;

    }
    int distinctSubseqII(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        prev.assign(n+1,0);

        vector<int> lastseen(26,0);

        for(int i=1;i<=n;i++){
            int idx = s[i-1] - 'a';
            prev[i] = lastseen[idx];
            lastseen[idx] = i;
        }

        return (subseq(n) - 1 + mod) % mod;
    }
};