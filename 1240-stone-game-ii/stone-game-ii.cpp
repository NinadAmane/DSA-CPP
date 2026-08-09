class Solution {
public:
    int solve(int ind, int m, bool turn, vector<int>& piles, vector<vector<vector<int>>>& dp){
        int n = piles.size();
        if(ind >= n){
            return dp[ind][m][turn] = 0;
        }
        if(dp[ind][m][turn] != -1) return dp[ind][m][turn];

        int stones = 0;
        if(turn){
            int ans = 0;
            for(int i=1;i<=2*m && ind + i <= n;i++){ //X=i
                stones += piles[ind + i - 1]; 
                int result = solve(ind+i, max(m,i), false, piles,dp);
                ans = max(ans, stones + result);
            }
            return dp[ind][m][turn] = ans;
        }
        else{
            int ans = INT_MAX;
            for(int i=1;i<=2*m && ind + i <= n;i++){ //X=i
                stones += piles[ind + i - 1];
                int result = solve(ind+i,max(m,i), true, piles,dp);
                ans = min(ans,  result);
            }

            return dp[ind][m][turn] = ans;
        }

        return dp[ind][m][turn] = 0;
        
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2,-1)));
        return solve(0, 1,true,piles, dp);
    }
};