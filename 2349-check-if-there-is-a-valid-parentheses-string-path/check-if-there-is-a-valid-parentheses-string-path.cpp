class Solution {
public:
    bool f(int i, int j, int balance, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || balance < 0) return false;
        if(i == n - 1 && j == m - 1) return balance == 1;
        if(dp[i][j][balance] != -1) return dp[i][j][balance];
        bool down = false;
        bool right = false;
        if(grid[i][j] == '('){
            down = f(i+1, j, balance + 1, grid,dp);
            right = f(i, j + 1, balance + 1, grid,dp);
        }
        else{
            down = f(i+1, j, balance - 1, grid,dp);
            right = f(i, j + 1, balance - 1, grid,dp);
            
        }
        return dp[i][j][balance] = down || right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == ')' || grid[n-1][m-1] == '(') return false;

        int bal = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m+n+1, -1)));
        return f(0,0,0,grid,dp);


    }
};