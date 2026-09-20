class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            int index = i+1;
            int rev = 26 - (s[i]-'a');
            int prod = rev*index;
            sum += prod;
        }
        cout << 26 - ( s[2] - 'a') << endl;
        return sum;
    }
};