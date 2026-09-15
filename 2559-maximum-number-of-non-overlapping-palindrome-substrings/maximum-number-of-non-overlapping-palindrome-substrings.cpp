class Solution {
public:
    int extend(int l, int r, string s){
        if(s.empty()) return 0;
        int n = s.size();
        while(l>=0 && r < n){
            if(s[l] == s[r]){
                r++;
                l--;
            }
            else{
                break;
            }
        }
        return r - l - 1;
    }
    bool ispalindrome(string s){
        int l =0;
        int r=s.size()-1;
        while(l<=r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n =s.size();
        
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < n){
            if(ispalindrome(s.substr(r, k)) && s.substr(r, k).size() >= k){
                ans++;
                r += k;
            }
            else if(ispalindrome(s.substr(r,  k + 1)) && s.substr(r, 1 + k).size() >= k){
                ans++;
                r += k+1;
            }
            else{
                r++;
            }
            
        }
        

        return ans;
    }
};