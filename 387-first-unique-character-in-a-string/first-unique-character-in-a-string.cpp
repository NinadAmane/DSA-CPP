class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        map<char, pair<int,int>> mp; //freq, indx
        
        for(int i=0;i<n;i++){
            mp[s[i]].first++;
            if(mp[s[i]].first == 1) mp[s[i]].second = i;
        }
        
        for(int i=0;i<n;i++){
            if(mp[s[i]].first == 1){
                return i;
            }
        }

        return -1;

        
    }
};