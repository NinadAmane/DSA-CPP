class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n=stones.size();
        vector<int> cnt(3,0);
        for(int i=0;i<n;i++){
            cnt[stones[i] % 3]++;
        }

        int diff = abs(cnt[1] - cnt[2]);
        if(cnt[0] % 2 == 0){
            return cnt[1] > 0 && cnt[2] > 0;
        }

        return diff > 2;

    }
};