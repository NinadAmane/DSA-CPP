class Solution {
public:
    bool f(int l, int r, int score1, int score2, bool turn,vector<int>& piles){
        int n = piles.size();
        if(l>r){
            return score1>score2;
        }

        if(turn){
            return f(l+1,r,score1 + piles[l],score2, false, piles) ||
                    f(l,r+1,score1 + piles[r],score2, false, piles);
        }
        else{
            return f(l+1,r,score1 ,score2 + piles[l], true, piles) &&
                    f(l,r+1,score1 ,score2 + piles[r], true, piles);
        }

        return true;
          
    }
    bool stoneGame(vector<int>& piles) {
        return f(0,0,0,0,true,piles);
    }
};