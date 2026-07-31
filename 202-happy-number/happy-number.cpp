class Solution {
public:
    bool isHappy(int n) {
        if(n == 1 || n == 7) return true;
        set<int> seen;

        while(n){
            seen.insert(n);
            int sum = 0;
            while(n){
                int x = n%10;
                n = n/10;
                sum += x*x;
            }
            if(sum == 1 || sum == 7) return true;
            if(seen.find(sum) != seen.end()){
                return false;
            }

            n=sum;
        }

        return true;
    }
};