class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m=needle.size();

        int start = 0;
        int ans = -1;
        while(start <= n - m){
            int i = start;
            int j = 0;

            while(j < m && haystack[i] == needle[j]){
                i++;
                j++;
            }

            if(j == m){
                ans = start;
                break;
            }

            start++;

        }


        return ans;
    }
};