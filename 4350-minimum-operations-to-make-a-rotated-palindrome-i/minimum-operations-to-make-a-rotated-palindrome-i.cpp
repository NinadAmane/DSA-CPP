class Solution {
public:
    int operationsneeded(int l, int r , string s){
        int n=s.size();
        int ans = 0;
        while(l<r){
            if(s[l] == s[r]){
               continue;
            }
            else{
                int a = s[l] - 'a';
                int b = s[r] - 'a';
                int diff = min(abs(a - b), 26 - abs(a - b));
                ans += diff;
            }
            l++;
            r--;
        }
        return ans;
    }
    int minOperations(string s) {
        int n = s.size();
        string ss = s + s;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int opsneed = operationsneeded(i,i + n-1, ss);
            int req = i;
            int ans = abs(opsneed + req);
            mini = min(mini, ans);
        }
        return mini;
    }
};