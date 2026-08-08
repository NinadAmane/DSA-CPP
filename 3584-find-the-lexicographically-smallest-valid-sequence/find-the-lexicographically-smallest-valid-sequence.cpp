class Solution {
public:
    // bool solve(string word1, string word2, int i, int j, bool turn, vector<int>& result,vector<vector<vector<int>>>& dp){
    //     if(j == word2.size()) return dp[i][j][turn] = true;
    //     if(i==word1.size() ) return dp[i][j][turn] = false;

    //     if(dp[i][j][turn] != -1) return dp[i][j][turn];

    //     if(word1[i] == word2[j]){
    //         result.push_back(i);
    //         if(solve(word1, word2, i+1, j+1,turn, result,dp)){
    //             return dp[i][j][turn] = true;
    //         }
    //         result.pop_back();
    //     }
        
    //     if(turn){
    //         result.push_back(i);
    //         if(solve(word1,word2, i + 1, j+1,false, result,dp)){
    //             return dp[i][j][turn] = true;
    //         }
    //         result.pop_back();
    //     }
        
    //     if(solve(word1,word2,i+1,j,turn,result,dp)){
    //         return dp[i][j][turn] = true;
    //     }
    
        
    //     return dp[i][j][turn] =false;
    // }
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> result;
        // vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(m + 1, vector<int>(2, -1)));
        // solve(word1,word2, 0,0,true, result,dp);

        int i=n-1;
        int j=m-1;
        int rightmatched = 0;
        vector<int> rightsidesesimilar(n+1,0);

        while(i>=0 && j>=0){
            if(word1[i] == word2[j]){
                rightmatched++;
                rightsidesesimilar[i] = rightmatched; 

                j--;
            }
            else{
                rightsidesesimilar[i] = rightmatched;
            }
            i--;
        }
        while(i >= 0) {
            rightsidesesimilar[i] = rightmatched;
            i--;
        }
        
        i=0, j=0;

        bool turn = true;
        while(i <n && j<m){
            if(word1[i] == word2[j]){
                result.push_back(i);
                // i++;
                j++;
            }

            else{
                if(turn && i+1 <n && rightsidesesimilar[i+1] >= m-j-1){
                    result.push_back(i);
                    turn = false;
                    // i++
                    j++;
                }
            }
            i++;
        }
        if(j==m) return result;
        return {};
    }
};