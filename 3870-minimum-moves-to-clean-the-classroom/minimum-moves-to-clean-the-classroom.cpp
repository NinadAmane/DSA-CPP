class Solution {
public:
    // int bfs(int row, int col, int e, int litters, int moves, vector<vector<string>>& grid, int totlitters){
    //     int n = classroom.size();
    //     int m = classroom[0].size();

    //     queue<pair<int,int>> q;
    //     int delrow[] = {-1,0,1,0};
    //     int delcol[] = {0,1,0,-1}; 

    //     while(!q.empty()){
    //         int r = q.front().first;
    //         int c = q.front().second;

    //         q.pop();

    //         moves++;
    //         if(grid[r][c] == "R"){
    //             energy = originalenergy;
    //         }
    //         if(totlitters == 0){
    //             return moves;
    //         }
    //         if(energy == 0 && totlitters > 0){
    //             return -1;
    //         }
    //         for(int i=0;i<4;i++){
    //             int nr = delrow[i] + r;
    //             int nc = delcol[i] + c;

    //             if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != "X" && energy > 0 && !vis[nr][nc]){
    //                 energy--;
    //                 vis[nr][nc] = 1;
    //                 if(grid[nr][nc] == "L"){
    //                     totlitters--;
    //                 }
    //                 q.push({nr,nc});
    //             }

    //         }
    //     }
    // }
    // int minMoves(vector<string>& classroom, int energy) {
    //     int n = classroom.size();
    //     int m = classroom[0].size();

    //     vector<vector<string>> grid(n, vector<string>(m));
    //     for(int i=0;i<n;i++){
    //         for(int j =0;j<m;j++){
    //             grid[i][j] = classroom[i][j];
    //         }
    //     }
        
    //     queue<pair<int,int>> q; //r , c
    //     vector<vector<int>> vis(n, vector<int>(m,0)); // 0 , 1
    //     int originalenergy = energy;

    //     int totlitters = 0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j] == "S"){
    //                 q.push({i,j});
    //                 vis[i][j] = 1;
    //             }
    //             else if(grid[i][j] == "L"){
    //                 totlitters++;
    //             }
    //             cout << grid[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << totlitters << " ";
    //     int moves = 0;
        

        
    //     return moves;
    // }

    struct state{
        int r;
        int c;
        int energy;
        int mask;
        int moves;
    };
     int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int sr = 0;
        int sc = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j] == 'S'){
                    sr=i;
                    sc = j;
                }
            }
        }

        vector<vector<int>> litterId(n, vector<int>(m, -1)); // NAME EACH LITTER IN A MASK.
        int id = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'L') {
                    litterId[i][j] = id++;
                }
            }
        }
        int litterCount = id;


        vector<vector<vector<vector<bool>>>> vis(n,vector<vector<vector<bool>>>(
        m,vector<vector<bool>>(energy + 1,vector<bool>(1 << litterCount, false))));
        vis[sr][sc][energy][0] = true;
        
        queue<state> q; 
        q.push({sr, sc, energy, 0,0});

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1}; 

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.r;
            int col = curr.c;
            int nrg = curr.energy;
            int mask = curr.mask;
            int moves = curr.moves;
            if(mask == (1 << litterCount) - 1)
                return moves;

            for(int i=0;i<4;i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                int nmask = mask;
                
                if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= m) continue;   

                if(classroom[nrow][ncol] == 'L'){
                    nmask |= (1 << litterId[nrow][ncol]);
                }

                int newenergy = nrg - 1;
                if(newenergy < 0) continue;

                if(classroom[nrow][ncol] == 'R')
                    newenergy = energy;

                if(classroom[nrow][ncol] == 'X')
                    continue;


                if(vis[nrow][ncol][newenergy][nmask])
                    continue;

            
                vis[nrow][ncol][newenergy][nmask] = true;
                q.push({nrow,ncol, newenergy, nmask, moves + 1});
                
            }
            
        }

        
        return -1;
    }
};