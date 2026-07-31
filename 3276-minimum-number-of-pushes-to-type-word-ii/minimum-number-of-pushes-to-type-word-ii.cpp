class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int pushes = 0;
        // for(int i=0;i<n;i++){
        //     pushes += (i/8) + 1;
        // }
        unordered_map<char,int> mp;
        for(auto x: word){
            mp[x]++;
        }
        priority_queue<pair<int,char>> pq;
        
        for(auto& it: mp){
            pq.push({it.second, it.first});
        }
        int rank = 0;
        while(!pq.empty()){
            pushes += (rank/8 + 1) * pq.top().first;
            rank++;
            pq.pop();
        }

        return pushes;
    }
};